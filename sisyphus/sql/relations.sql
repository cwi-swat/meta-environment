\pset format unaligned
\pset fieldsep ',' 
\pset recordsep '\n'


select name as _component
from si_components;

select name as _revision_name, version as _version 
from si_components, si_revisions 
where si_component_id = si_components.id;

select i.id as _build, name as _name, version as _version 
from si_components c, si_revisions r, si_items i
where si_component_id = c.id and i.si_revision_id = r.id;

select s.time as _session, i.id as _build, name as _name, version as _version 
from si_sessions s, si_components c, si_revisions r, si_items i
where si_component_id = c.id and i.si_revision_id = r.id and i.si_session_id = s.id;


select i.id as _successful_build, name as _name, version as _version
from si_components c, si_revisions r, si_items i
where si_component_id = c.id and i.si_revision_id = r.id and i.success = true;


select 
i1.id as _build, c1.name as _name, r1.version as _version,
i2.id as _dep_build, c2.name as _dep_name, r2.version as _dep_version
from 
si_components c1, si_revisions r1, si_items i1,
si_components c2, si_revisions r2, si_items i2,
si_item_deps d
where 
r1.si_component_id = c1.id and i1.si_revision_id = r1.id and
r2.si_component_id = c2.id and i2.si_revision_id = r2.id and
d.si_item_id = i1.id and d.si_dep_id = i2.id;


