CREATE TABLE "Storage@EcosystemTeam".Ecosystem
(
 ecosystem_id      serial NOT NULL,
 storage_policy_id bigint NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( ecosystem_id ),
 CONSTRAINT FK_1 FOREIGN KEY ( storage_policy_id ) REFERENCES "Storage@EcosystemTeam".StoragePolicy ( storage_policy_id )
);
CREATE INDEX FK_2 ON "Storage@EcosystemTeam".Ecosystem
(
 storage_policy_id
);


CREATE TABLE "Storage@EcosystemTeam".Component
(
 component_id bigserial NOT NULL,
 ui_logo           varchar(50) NULL,
 time_install      timestamp NOT NULL,
 time_update       timestamp NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( component_id )
);
CREATE TABLE "Storage@EcosystemTeam"."Ecosystem-Component"
(
 component_id bigint NOT NULL,
 ecosystem_id      int NOT NULL,
 CONSTRAINT PK_2 PRIMARY KEY ( component_id, ecosystem_id ),
 CONSTRAINT FK_6_1 FOREIGN KEY ( component_id ) REFERENCES "Storage@EcosystemTeam".Component ( component_id ),
 CONSTRAINT FK_7 FOREIGN KEY ( ecosystem_id ) REFERENCES "Storage@EcosystemTeam".Ecosystem ( ecosystem_id )
);
CREATE INDEX FK_1 ON "Storage@EcosystemTeam"."Ecosystem-Component"
(
 component_id
);
CREATE INDEX FK_3 ON "Storage@EcosystemTeam"."Ecosystem-Component"
(
 ecosystem_id
);


CREATE TABLE "Storage@EcosystemTeam".StoragePolicy
(
 storage_policy_id           bigserial NOT NULL,
 use_shared_views            boolean NOT NULL,
 space_restriction_policy_id bigint NOT NULL,
 create_time                 timestamp NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( storage_policy_id ),
 CONSTRAINT FK_2 FOREIGN KEY ( space_restriction_policy_id ) REFERENCES "Storage@EcosystemTeam".SpaceRestrictionPolicy ( space_restriction_policy_id )
);
CREATE INDEX FK_2 ON "Storage@EcosystemTeam".StoragePolicy
(
 space_restriction_policy_id
);


CREATE TABLE "Storage@EcosystemTeam".SpaceRestrictionPolicy
(
 space_restriction_policy_id bigserial NOT NULL,
 ui_name                     varchar(50) NOT NULL,
 create_time                 timestamp NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( space_restriction_policy_id )
);


CREATE TABLE "Storage@EcosystemTeam".UserRestriction
(
 parent_policy_id      bigint NOT NULL,
 user_id               bigint NOT NULL,
 max_size              bigint NOT NULL,
 is_allow_partitioning boolean NOT NULL,
 max_partition_count   bigint NOT NULL,
 CONSTRAINT PK_2 PRIMARY KEY ( parent_policy_id, user_id ),
 CONSTRAINT FK_3 FOREIGN KEY ( parent_policy_id ) REFERENCES "Storage@EcosystemTeam".SpaceRestrictionPolicy ( space_restriction_policy_id ),
 CONSTRAINT FK_6 FOREIGN KEY ( user_id ) REFERENCES ExternalView_User ( user_id )
);
CREATE INDEX FK_1 ON "Storage@EcosystemTeam".UserRestriction
(
 parent_policy_id
);
CREATE INDEX FK_3 ON "Storage@EcosystemTeam".UserRestriction
(
 user_id
);
CREATE TABLE ExternalView_User
(
 user_id bigserial NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( user_id )
);


CREATE TABLE "Storage@EcosystemTeam".ComponentRestriction
(
 parent_policy_id  bigint NOT NULL,
 component_id bigint NOT NULL,
 max_size          bigint NOT NULL,
 CONSTRAINT PK_2 PRIMARY KEY ( parent_policy_id, component_id ),
 CONSTRAINT FK_4 FOREIGN KEY ( parent_policy_id ) REFERENCES "Storage@EcosystemTeam".SpaceRestrictionPolicy ( space_restriction_policy_id ),
 CONSTRAINT FK_8 FOREIGN KEY ( component_id ) REFERENCES "Storage@EcosystemTeam".Component ( component_id )
);
CREATE INDEX FK_2 ON "Storage@EcosystemTeam".ComponentRestriction
(
 parent_policy_id
);
CREATE INDEX FK_3 ON "Storage@EcosystemTeam".ComponentRestriction
(
 component_id
);


-- Manifest
CREATE TABLE "Storage@EcosystemTeam".Manifest
(
 manifest_id    bigserial NOT NULL,
 hash           varchar(512) NOT NULL,
 scheme_id      bigint NOT NULL,
 name           varchar(80) NOT NULL,
 ui_name        varchar(80) NOT NULL,
 ui_description varchar(350) NOT NULL,
 version        varchar(50) NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( manifest_id ),
 CONSTRAINT FK_11 FOREIGN KEY ( scheme_id ) REFERENCES "Storage@EcosystemTeam".ManifestScheme ( scheme_id )
);
CREATE TABLE "Storage@EcosystemTeam"."Component-Manifest"
(
 component_info_id bigint NOT NULL,
 manifest_id       bigint NOT NULL,
 CONSTRAINT PK_2 PRIMARY KEY ( component_info_id, manifest_id ),
 CONSTRAINT FK_9 FOREIGN KEY ( component_info_id ) REFERENCES "Storage@EcosystemTeam".ComponentInfo ( component_info_id ),
 CONSTRAINT FK_10 FOREIGN KEY ( manifest_id ) REFERENCES "Storage@EcosystemTeam".Manifest ( manifest_id )
);
CREATE INDEX FK_1 ON "Storage@EcosystemTeam"."Component-Manifest"
(
 component_info_id
);
CREATE INDEX FK_3 ON "Storage@EcosystemTeam"."Component-Manifest"
(
 manifest_id
);

CREATE INDEX FK_2 ON "Storage@EcosystemTeam".Manifest
(
 scheme_id
);


CREATE TABLE "Storage@EcosystemTeam".ManifestScheme
(
 scheme_id         bigint NOT NULL,
 field_description jsonb NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( scheme_id )
);

--    Begin Manifest fields:
--       NetworkAccess
CREATE TABLE "Storage@EcosystemTeam".NetworkAccess
(
 net_access_id bigserial NOT NULL,
 "uri"           varchar(500) NOT NULL,
 protocol      varchar(50) NOT NULL,
 port          int NOT NULL,
 is_optional   boolean NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( net_access_id )
);

CREATE TABLE "Storage@EcosystemTeam"."NetworkAccess-Manifest"
(
 field_id    bigint NOT NULL,
 manifest_id bigint NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( field_id, manifest_id ),
 CONSTRAINT FK_14 FOREIGN KEY ( field_id ) REFERENCES "Storage@EcosystemTeam".NetworkAccess ( net_access_id ),
 CONSTRAINT FK_15 FOREIGN KEY ( manifest_id ) REFERENCES "Storage@EcosystemTeam".Manifest ( manifest_id )
);

CREATE INDEX FK_1 ON "Storage@EcosystemTeam"."NetworkAccess-Manifest"
(
 field_id
);

CREATE INDEX FK_3 ON "Storage@EcosystemTeam"."NetworkAccess-Manifest"
(
 manifest_id
);
--       /NetworkAccess

--       BaseInfo
CREATE TABLE "Storage@EcosystemTeam".BaseInfo
(
 base_info_id   bigserial NOT NULL,
 min_sdk_ver    int NOT NULL,
 target_sdk_ver int NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( base_info_id )
);

CREATE TABLE "Storage@EcosystemTeam"."BaseInfo-Manifest"
(
 base_info_id bigint NOT NULL,
 manifest_id  bigint NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( base_info_id, manifest_id ),
 CONSTRAINT FK_18 FOREIGN KEY ( base_info_id ) REFERENCES "Storage@EcosystemTeam".BaseInfo ( base_info_id ),
 CONSTRAINT FK_19 FOREIGN KEY ( manifest_id ) REFERENCES "Storage@EcosystemTeam".Manifest ( manifest_id )
);
CREATE INDEX FK_1 ON "Storage@EcosystemTeam"."BaseInfo-Manifest"
(
 base_info_id
);
CREATE INDEX FK_3 ON "Storage@EcosystemTeam"."BaseInfo-Manifest"
(
 manifest_id
);
-- 		/BaseInfo

-- 		ComponentPartInfo
CREATE TABLE "Storage@EcosystemTeam".ComponentPartInfo
(
 component_part_info_id bigserial NOT NULL,
 type                   int NOT NULL,
 priority               int NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( component_part_info_id )
);

CREATE TABLE "Storage@EcosystemTeam"."ComponentPartInfo-Manifest"
(
 manifest_id bigint NOT NULL,
 field_id    bigint NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( manifest_id, field_id ),
 CONSTRAINT FK_12 FOREIGN KEY ( manifest_id ) REFERENCES "Storage@EcosystemTeam".Manifest ( manifest_id ),
 CONSTRAINT FK_13 FOREIGN KEY ( field_id ) REFERENCES "Storage@EcosystemTeam".ComponentPartInfo ( component_part_info_id )
);
CREATE INDEX FK_2 ON "Storage@EcosystemTeam"."ComponentPartInfo-Manifest"
(
 manifest_id
);
CREATE INDEX FK_3 ON "Storage@EcosystemTeam"."ComponentPartInfo-Manifest"
(
 field_id
);
-- 		/ComponentPartInfo

-- 		FilesystemAccess
CREATE TABLE "Storage@EcosystemTeam".FilesystemAccess
(
 fs_access_id bigserial NOT NULL,
 "path"         varchar(500) NOT NULL,
 permissions  char(10) NOT NULL,
 type         int NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( fs_access_id )
);


CREATE TABLE "Storage@EcosystemTeam"."FilesystemAccess-Manifest"
(
 fs_access_id bigint NOT NULL,
 manifest_id  bigint NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( fs_access_id, manifest_id ),
 CONSTRAINT FK_16 FOREIGN KEY ( fs_access_id ) REFERENCES "Storage@EcosystemTeam".FilesystemAccess ( fs_access_id ),
 CONSTRAINT FK_17 FOREIGN KEY ( manifest_id ) REFERENCES "Storage@EcosystemTeam".Manifest ( manifest_id )
);
CREATE INDEX FK_2 ON "Storage@EcosystemTeam"."FilesystemAccess-Manifest"
(
 fs_access_id
);
CREATE INDEX FK_3 ON "Storage@EcosystemTeam"."FilesystemAccess-Manifest"
(
 manifest_id
);
-- 		/FilesystemAccess
-- End Manifest fields
