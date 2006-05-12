
drop table contexts cascade;
create table contexts (
	id serial primary key,
	created_on timestamp,

	/* Essential */
	host text,
	profile_name text,
	profile_version integer,
	sources_version integer,

	/* Semi-essential */

	sisyphus_version integer,

	/* Accidental */
	session_time timestamp,

	unique (host, profile_name, profile_version, sources_version)

);

drop table builds cascade;
create table builds (
	id serial primary key,
	created_on timestamp,

	context_id integer references contexts,

	package_name text,
	package_version text,


	success boolean default null,

	unique (context_id, package_name, package_version)
);


drop table build_dependencies cascade;
create table build_dependencies (
	build_id integer references builds,
	dependency_id integer references builds,
	primary key (build_id, dependency_id)
);


drop table build_steps cascade;
create table build_steps (
	id serial primary key,	
	build_id references builds,

	created_on timestamp,

	script text,
	stderr text,
	stdout text,

	success boolean,

	unique (build_id, script)
);





drop table transitive_build_dependencies cascade;
create table transitive_build_dependencies (
	build_id integer references builds,
	transitive_dependency_id integer references builds
);	

create rule maintain_transitive_closure as on insert to build_dependencies do
create temporary table new_transitive_closure (
	build_id integer,
	transitive_dependency_id integer
);
select * from (
	select start = transitive_build_dependencies.build_id, end = new.dependency_id
	from transitive_build_dependencies where transitive_build_dependencies.transitive_dependency_id = new.build_id
	union
	select start = new.build_id , end = transitive_build_dependencies.transitive_dependency_id
	from transitive_build_dependencies where new.dependency_id = transitive_build_dependencies.build_id
	union
	select start = tc1.build_id, end = tc2.transitive_dependency_id
	from transitive_build_dependencies as tc1, transitive_build_dependencies as tc2,
	where tc1.transitive_dependency_id = new.build_id and tc2.build_id = dependency_id
) as T
into new_transitive_closure;

insert into new_transitive_closure values(new.build_id, new.dependency_id);


create temporary table delta (
	build_id integer,
	transitive_dependency_id integer
);
select * from new_transitive_closure as new_transitive_closure
where not exists (
	select * from transitive_build_dependencies
	where 
		transitive_build_dependencies.build_id = new_transitive_closure.build_id and
		transitive_build_dependencies.transitive_dependency_id = new_transitive_closure.transitive_dependency_id)
into delta;
insert into transitive_build_dependencies (select * from delta);
end
;

