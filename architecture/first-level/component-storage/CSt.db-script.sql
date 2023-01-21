CREATE TABLE "Component"
(
 component_id bigserial NOT NULL,
 ui_logo           varchar(50) NULL,
 time_install      timestamp with time zone NOT NULL,
 time_update       timestamp with time zone NOT NULL,
 PRIMARY KEY ( component_id )
);

CREATE TABLE "SpaceRestrictionPolicy"
(
 space_restriction_policy_id bigserial NOT NULL,
 ui_name                     varchar(50) NOT NULL,
 create_time                 timestamp with time zone NOT NULL,
 PRIMARY KEY ( space_restriction_policy_id )
);

CREATE TABLE "ComponentRestriction"
(
 parent_policy_id  bigint NOT NULL,
 component_id bigint NOT NULL,
 max_size          bigint NOT NULL,
 PRIMARY KEY ( parent_policy_id, component_id ),
 FOREIGN KEY ( parent_policy_id ) REFERENCES "SpaceRestrictionPolicy" ( space_restriction_policy_id ),
 FOREIGN KEY ( component_id ) REFERENCES "Component" ( component_id )
);

CREATE TABLE "ExternalView_User"
(
 user_id bigserial NOT NULL,
 PRIMARY KEY ( user_id )
);

CREATE TABLE "UserRestriction"
(
 parent_policy_id      bigint NOT NULL,
 user_id               bigint NOT NULL,
 max_size              bigint NOT NULL,
 is_allow_partitioning boolean NOT NULL,
 max_partition_count   bigint NOT NULL,
 PRIMARY KEY ( parent_policy_id, user_id ),
 FOREIGN KEY ( parent_policy_id ) REFERENCES "SpaceRestrictionPolicy" ( space_restriction_policy_id ),
 FOREIGN KEY ( user_id ) REFERENCES "ExternalView_User" ( user_id )
);
CREATE INDEX INDEX_1 ON "UserRestriction"
(
 parent_policy_id
);
CREATE INDEX INDEX_2 ON "UserRestriction"
(
 user_id
);

CREATE TABLE "StoragePolicy"
(
 storage_policy_id           bigserial NOT NULL,
 use_shared_views            boolean NOT NULL,
 space_restriction_policy_id bigint NOT NULL,
 create_time                 timestamp with time zone NOT NULL,
 PRIMARY KEY ( storage_policy_id ),
 FOREIGN KEY ( space_restriction_policy_id ) REFERENCES "SpaceRestrictionPolicy" ( space_restriction_policy_id )
);
CREATE INDEX INDEX_3 ON "StoragePolicy"
(
 space_restriction_policy_id
);

CREATE TABLE "Ecosystem"
(
 ecosystem_id      serial NOT NULL,
 storage_policy_id bigint NOT NULL,
 is_active boolean NOT NULL DEFAULT false,
 PRIMARY KEY ( ecosystem_id ),
 FOREIGN KEY ( storage_policy_id ) REFERENCES "StoragePolicy" ( storage_policy_id )
);
CREATE INDEX INDEX_4 ON "Ecosystem"
(
 storage_policy_id
);

CREATE TABLE "Ecosystem-Component"
(
 component_id bigint NOT NULL,
 ecosystem_id      int NOT NULL,
 PRIMARY KEY ( component_id, ecosystem_id ),
 FOREIGN KEY ( component_id ) REFERENCES "Component" ( component_id ),
 FOREIGN KEY ( ecosystem_id ) REFERENCES "Ecosystem" ( ecosystem_id )
);
CREATE INDEX INDEX_5 ON "Ecosystem-Component"
(
 component_id
);
CREATE INDEX INDEX_6 ON "Ecosystem-Component"
(
 ecosystem_id
);


CREATE INDEX INDEX_7 ON "ComponentRestriction"
(
 parent_policy_id
);
CREATE INDEX INDEX_8 ON "ComponentRestriction"
(
 component_id
);


-- Manifest

CREATE TABLE "ManifestScheme"
(
 scheme_id         bigserial NOT NULL,
 field_description jsonb NOT NULL,
 PRIMARY KEY ( scheme_id )
);

CREATE TABLE "Manifest"
(
 manifest_id    bigserial NOT NULL,
 hash           varchar(512) NOT NULL,
 scheme_id      bigint NOT NULL,
 name           varchar(80) NOT NULL,
 ui_name        varchar(80) NOT NULL,
 ui_description varchar(350) NOT NULL,
 version        varchar(50) NOT NULL,
 PRIMARY KEY ( manifest_id ),
 FOREIGN KEY ( scheme_id ) REFERENCES "ManifestScheme" ( scheme_id )
);
CREATE TABLE "Component-Manifest"
(
 component_id bigint NOT NULL,
 manifest_id       bigint NOT NULL,
 PRIMARY KEY ( component_id, manifest_id ),
 FOREIGN KEY ( component_id ) REFERENCES "Component" ( component_id ),
 FOREIGN KEY ( manifest_id ) REFERENCES "Manifest" ( manifest_id )
);
CREATE INDEX INDEX_9 ON "Component-Manifest"
(
 component_id
);
CREATE INDEX INDEX_10 ON "Component-Manifest"
(
 manifest_id
);

CREATE INDEX INDEX_11 ON "Manifest"
(
 scheme_id
);


--    Begin "Manifest" fields:
--       NetworkAccess
CREATE TABLE "NetworkAccess"
(
 net_access_id bigserial NOT NULL,
 "uri"           varchar(500) NOT NULL,
 protocol      varchar(50) NOT NULL,
 port          int NOT NULL,
 is_optional   boolean NOT NULL,
 PRIMARY KEY ( net_access_id )
);

   CREATE TABLE "NetworkAccess-Manifest"
   (
   field_id    bigint NOT NULL,
   manifest_id bigint NOT NULL,
   PRIMARY KEY ( field_id, manifest_id ),
   FOREIGN KEY ( field_id ) REFERENCES "NetworkAccess" ( net_access_id ),
   FOREIGN KEY ( manifest_id ) REFERENCES "Manifest" ( manifest_id )
   );

CREATE INDEX INDEX_12 ON "NetworkAccess-Manifest"
(
 field_id
);

CREATE INDEX INDEX_13 ON "NetworkAccess-Manifest"
(
 manifest_id
);
--       /NetworkAccess

--       BaseInfo
CREATE TABLE "BaseInfo"
(
 base_info_id   bigserial NOT NULL,
 min_sdk_ver    int NOT NULL,
 target_sdk_ver int NOT NULL,
 PRIMARY KEY ( base_info_id )
);

CREATE TABLE "BaseInfo-Manifest"
(
 base_info_id bigint NOT NULL,
 manifest_id  bigint NOT NULL,
 PRIMARY KEY ( base_info_id, manifest_id ),
 FOREIGN KEY ( base_info_id ) REFERENCES "BaseInfo" ( base_info_id ),
 FOREIGN KEY ( manifest_id ) REFERENCES "Manifest" ( manifest_id )
);
CREATE INDEX INDEX_14 ON "BaseInfo-Manifest"
(
 base_info_id
);
CREATE INDEX INDEX_15 ON "BaseInfo-Manifest"
(
 manifest_id
);
-- 		/BaseInfo

-- 		ComponentPartInfo
CREATE TABLE "ComponentPartInfo"
(
 component_part_info_id bigserial NOT NULL,
 type                   int NOT NULL,
 priority               int NOT NULL,
 PRIMARY KEY ( component_part_info_id )
);

CREATE TABLE "ComponentPartInfo-Manifest"
(
 manifest_id bigint NOT NULL,
 field_id    bigint NOT NULL,
 PRIMARY KEY ( manifest_id, field_id ),
 FOREIGN KEY ( manifest_id ) REFERENCES "Manifest" ( manifest_id ),
 FOREIGN KEY ( field_id ) REFERENCES "ComponentPartInfo" ( component_part_info_id )
);
CREATE INDEX INDEX_16 ON "ComponentPartInfo-Manifest"
(
 manifest_id
);
CREATE INDEX INDEX_17 ON "ComponentPartInfo-Manifest"
(
 field_id
);
-- 		/ComponentPartInfo

-- 		FilesystemAccess
CREATE TABLE "FilesystemAccess"
(
 fs_access_id bigserial NOT NULL,
 "path"         varchar(500) NOT NULL,
 permissions  char(10) NOT NULL,
 type         int NOT NULL,
 PRIMARY KEY ( fs_access_id )
);


CREATE TABLE "FilesystemAccess-Manifest"
(
 fs_access_id bigint NOT NULL,
 manifest_id  bigint NOT NULL,
 PRIMARY KEY ( fs_access_id, manifest_id ),
 FOREIGN KEY ( fs_access_id ) REFERENCES "FilesystemAccess" ( fs_access_id ),
 FOREIGN KEY ( manifest_id ) REFERENCES "Manifest" ( manifest_id )
);
CREATE INDEX INDEX_18 ON "FilesystemAccess-Manifest"
(
 fs_access_id
);
CREATE INDEX INDEX_19 ON "FilesystemAccess-Manifest"
(
 manifest_id
);
-- 		/FilesystemAccess
-- End "Manifest" fields
