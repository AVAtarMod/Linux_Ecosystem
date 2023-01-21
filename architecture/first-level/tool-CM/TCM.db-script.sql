CREATE TABLE "ExternalView_Component Info"
(
 component_id bigserial NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( component_id )
);

CREATE TABLE "Component status"
(
 component_id bigint NOT NULL,
 is_enabled   boolean NOT NULL,
 status       int NOT NULL,
 CONSTRAINT PK_2 PRIMARY KEY ( component_id ),
 CONSTRAINT FK_4 FOREIGN KEY ( component_id ) REFERENCES "ExternalView_Component Info" ( component_id )
);

CREATE INDEX FK_1 ON "Component status"
(
 component_id
);

CREATE TABLE "Component dependency"
(
 component_id  bigint NOT NULL,
 dependency_id bigint NOT NULL,
 is_strict     boolean NOT NULL,
 CONSTRAINT PK_2 PRIMARY KEY ( component_id, dependency_id ),
 CONSTRAINT FK_3_1 FOREIGN KEY ( component_id ) REFERENCES "Component status" ( component_id ),
 CONSTRAINT FK_4_1 FOREIGN KEY ( dependency_id ) REFERENCES "Component status" ( component_id )
);

CREATE INDEX FK_1 ON "Component dependency"
(
 component_id
);

CREATE INDEX FK_3 ON "Component dependency"
(
 dependency_id
);

CREATE TABLE "Component endpoint"
(
 endpoint_id  serial NOT NULL,
 name        text  NOT NULL,
 component_id bigint NOT NULL,
 CONSTRAINT PK_1 PRIMARY KEY ( endpoint_id ),
 CONSTRAINT FK_3 FOREIGN KEY ( component_id ) REFERENCES "Component status" ( component_id )
);

CREATE INDEX FK_2 ON "Component endpoint"
(
 component_id
);
