
/*

drop table si_repositories cascade;
create table si_repositories (
	id serial primary key,
	location text not null unique
);

drop table si_variants cascade;
create table si_variants (
	id serial primary key,
	name varchar(1024) default 'trunk',
	si_component_id integer references si_components,
	unique (name, si_component_id)
)
*/



drop table si_platforms cascade;
create table si_platforms (
	id serial primary key,
	kernel_name varchar(32),
	kernel_release varchar(32),
	hardware_platform varchar(32),
	hardware_class varchar(32),
	processor_type varchar(32),
	unique (kernel_name, kernel_release, hardware_platform, hardware_class, processor_type)
);

drop table si_components cascade;
create table si_components (
	id serial primary key,
	name varchar(32) not null unique
);



drop table si_revisions cascade;
create table si_revisions (
	id serial primary key,
	si_component_id integer references si_components,
	version integer,
	changelog_diff text,
	informative_version char(16) default 'unavailable', 
	unique (si_component_id, version)
);


drop table si_profiles cascade;
create table si_profiles (
	id serial primary key,
	name varchar(32) not null,
	version integer,
	unique (name, version)
);

drop table si_hosts cascade;
create table si_hosts (
	id serial primary key,
	si_platform_id integer references si_platforms,
	uname varchar(512) not null unique,
	status text,
	progress text
);


drop table si_configs cascade;
create table si_configs (
	id serial primary key,
	si_profile_id integer references si_profiles,
	sources_version integer,
	script_version integer,
	unique (sources_version, script_version, si_profile_id)
);
	

drop table si_sessions cascade;
create table si_sessions (
	id serial primary key,
	time timestamp not null unique
);


drop table si_items cascade;
create table si_items (
	id serial primary key, 
	si_host_id integer references si_hosts,
	si_revision_id integer references si_revisions,
	si_config_id integer references si_configs,
	si_session_id integer references si_sessions,
	progress boolean,
	success boolean,
	released boolean default false, 
	unique (si_host_id, si_revision_id, si_config_id)
);

drop table si_item_deps cascade;
create table si_item_deps (
	si_item_id integer references si_items,
	si_dep_id integer references si_items,
	unique (si_item_id, si_dep_id)
);

drop table si_results cascade;
create table si_results (
	id serial primary key,
	si_item_id integer references si_items,
	command text
	environment text,,
	output text,
	error_output text,
	success boolean,
	action text default "unspecified",
	unique (command, si_item_id)
);

drop table si_logs cascade;
create table si_logs (
	id serial primary key,
	si_host_id integer references si_hosts,
	created_on timestamp,
	line text
);


drop table si_releases cascade;
create table si_releases (
	id serial primary key,
	si_component_id integer references si_components,
	si_item_id integer references si_items,
	version char(16)
);


create view si_builds (id, name, version, informative_version, si_item_id) as
select 
	si_items.id, 
	si_components.name, 
	si_revisions.version,
	si_revisions.informative_version,
	si_items.id
from
	si_items, 
	si_components,
	si_revisions
where
	si_revisions.si_component_id = si_components.id and
	si_items.si_revision_id = si_revisions.id and
	si_items.success = true
;

	
