

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


select name, sum(count) from si_components, si_revisions,
revision_not_tried_count_pre_backtracking where
si_revisions.si_component_id = si_components.id and si_revisions.id =
revision_not_tried_count_pre_backtracking.si_revision_id group by
name order by name;

/* After */

create temp table revision_not_tried_count_post_backtracking as select
si_revision_id, count(si_items.id) from si_items, si_sessions where
si_items.id not in (select * from tried_items) and si_session_id =
si_sessions.id and si_sessions.time >= '2006-08-01' group by
si_revision_id order by si_revision_id;


select name, sum(count) from si_components, si_revisions,
revision_not_tried_count_post_backtracking where
si_revisions.si_component_id = si_components.id and si_revisions.id =
revision_not_tried_count_post_backtracking.si_revision_id group by
name order by name;

/* Results at 15-3-2007 16:17


Stats

Pre backtracking (< 1-8-2006)
4499 total nottrieds
17137 total builds
11565 success
5572 failure

Post backtracking
1163 total nottrieds
11060 total builds
9391 success
1670 failure

Pre

          name          | sum
------------------------+-----
 apigen                 |  45
 asc-support            | 134
 asf                    | 190
 asf-library            |  16
 asfsdf-meta            | 399
 asf-support            | 107
 aterm                  |   3
 aterm-java             |  75
 balanced-binary-aterms |  12
 config-manager         |  81
 config-support         |  46
 dialog-gui             | 113
 editor-manager         |  40
 editor-plugin          | 158
 error-gui              | 159
 error-support          |  74
 graph-gui              | 135
 graph-support          | 120
 io-support             |  44
 JJTraveler             |  17
 JRelCal                |   3
 meta                   | 376
 meta-build-env         |   2
 meta-doc               |   3
 meta-studio            | 139
 module-details-gui     | 101
 module-manager         | 168
 module-support         |   3
 navigator-gui          | 141
 pandora                | 121
 pgen                   | 151
 progress-gui           | 104
 pt-support             |  92
 relational-aterms      |  21
 sdf-apigen             | 122
 sdf-library            |   3
 sdf-meta               | 207
 sdf-support            | 123
 sglr                   | 121
 shared-objects         |  19
 sisyphus               |   4
 structure-editor       |  70
 term-store             |  32
 tide                   | 150
 tide-support           |  61
 toolbus                |  76
 toolbus-java-adapter   |  62
 toolbuslib             |  56
(48 rows)


Post

        name         | sum
----------------------+-----
 apigen               |  16
 asc-support          |  37
 asf                  |  61
 asf-library          |  26
 asfsdf-meta          | 135
 asf-support          |  20
 aterm                |  19
 aterm-java           |  11
 config-manager       |  11
 config-support       |  11
 console-grabber      |   8
 console-gui          |   6
 dialog-gui           |  23
 editor-manager       |  12
 editor-plugin        |  31
 error-gui            |  25
 error-support        |  17
 graph-gui            |  31
 graph-support        |  14
 io-support           |  16
 JJTraveler           |  10
 meta                 |  63
 meta-autotools       |   3
 meta-build-env       |  14
 meta-doc             |  25
 meta-studio          |  27
 module-details-gui   |  22
 module-manager       |  33
 module-support       |   9
 navigator-gui        |  27
 pandora              |  17
 pgen                 |  28
 progress-gui         |  23
 pt-support           |  18
 relational-aterms    |   3
 rscript              |   2
 sdf                  |   8
 sdf-apigen           |  20
 sdf-library          |  20
 sdf-meta             |  87
 sdf-pretty           |   1
 sdf-support          |  23
 sglr                 |  18
 shared-objects       |  11
 sisyphus             |   1
 structure-editor     |  12
 term-store           |  11
 tide                 |  24
 tide-support         |  17
 toolbus              |  21
 toolbus-java-adapter |  10
 toolbuslib           |  25
(52 rows)


*/
