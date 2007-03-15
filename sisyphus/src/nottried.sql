

create temp table tried_items as select distinct si_item_id from si_results;


create temp table revision_not_tried_count as select si_revision_id,
count(id) from si_items where id not in (select * from tried_items)
group by si_revision_id order by si_revision_id;


select name, count(count) from si_components, si_revisions,
revision_not_tried_count where si_revisions.si_component_id =
si_components.id and si_revisions.id =
revision_not_tried_count.si_revision_id group by name;


/* Different time frames. */


create temp table tried_items as select distinct si_item_id from si_results;

/* Before backtracking */

create temp table revision_not_tried_count_pre_backtracking as select
si_revision_id, count(si_items.id) from si_items, si_sessions where
si_items.id not in (select * from tried_items) and si_session_id =
si_sessions.id and si_sessions.time < '2006-08-01' group by
si_revision_id order by si_revision_id;


select name, count(count) from si_components, si_revisions,
revision_not_tried_count_pre_backtracking where
si_revisions.si_component_id = si_components.id and si_revisions.id =
revision_not_tried_count_pre_backtracking.si_revision_id group by
name;

/* After */

create temp table revision_not_tried_count_post_backtracking as select
si_revision_id, count(si_items.id) from si_items, si_sessions where
si_items.id not in (select * from tried_items) and si_session_id =
si_sessions.id and si_sessions.time >= '2006-08-01' group by
si_revision_id order by si_revision_id;


select name, count(count) from si_components, si_revisions,
revision_not_tried_count_post_backtracking where
si_revisions.si_component_id = si_components.id and si_revisions.id =
revision_not_tried_count_post_backtracking.si_revision_id group by
name;

/* Results at 15-3-2007 16:05

Pre

          name          | count
------------------------+-------
 apigen                 |    15
 asc-support            |    22
 asf                    |    45
 asf-library            |     7
 asfsdf-meta            |    78
 asf-support            |     9
 aterm                  |     3
 aterm-java             |    15
 balanced-binary-aterms |     3
 config-manager         |    14
 config-support         |     9
 dialog-gui             |    21
 editor-manager         |    10
 editor-plugin          |    32
 error-gui              |    25
 error-support          |    15
 graph-gui              |    23
 graph-support          |    19
 io-support             |    12
 JJTraveler             |     3
 JRelCal                |     2
 meta                   |   101
 meta-build-env         |     2
 meta-doc               |     2
 meta-studio            |    31
 module-details-gui     |    17
 module-manager         |    40
 module-support         |     2
 navigator-gui          |    21
 pandora                |    18
 pgen                   |    28
 progress-gui           |    19
 pt-support             |    27
 relational-aterms      |     3
 sdf-apigen             |    17
 sdf-library            |     2
 sdf-meta               |    54
 sdf-support            |    20
 sglr                   |    27
 shared-objects         |     4
 sisyphus               |     4
 structure-editor       |    14
 term-store             |     8
 tide                   |    20
 tide-support           |     9
 toolbus                |    13
 toolbus-java-adapter   |    10
 toolbuslib             |     7


Post

         name         | count
----------------------+-------
 apigen               |     7
 asc-support          |     9
 asf                  |    12
 asf-library          |    17
 asfsdf-meta          |    26
 asf-support          |     5
 aterm                |     9
 aterm-java           |     2
 config-manager       |     3
 config-support       |     2
 console-grabber      |     5
 console-gui          |     3
 dialog-gui           |     3
 editor-manager       |     3
 editor-plugin        |    12
 error-gui            |     5
 error-support        |     4
 graph-gui            |     6
 graph-support        |     4
 io-support           |     5
 JJTraveler           |     2
 meta                 |    18
 meta-autotools       |     1
 meta-build-env       |     6
 meta-doc             |    20
 meta-studio          |     7
 module-details-gui   |     2
 module-manager       |    10
 module-support       |     3
 navigator-gui        |     4
 pandora              |     4
 pgen                 |     7
 progress-gui         |     4
 pt-support           |     6
 relational-aterms    |     1
 rscript              |     2
 sdf                  |     1
 sdf-apigen           |     1
 sdf-library          |    13
 sdf-meta             |    23
 sdf-pretty           |     1
 sdf-support          |     6
 sglr                 |     3
 shared-objects       |     3
 sisyphus             |     1
 structure-editor     |     2
 term-store           |     1
 tide                 |     3
 tide-support         |     3
 toolbus              |     8
 toolbus-java-adapter |     2
 toolbuslib           |     3


*/
