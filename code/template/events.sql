table1:{UPDATE,DELETE}
table2:{DELETE}

MANIFEST:
cm@orig:component_status.is_enabled:{UPDATE}
--------------
CREATE TABLE component_status.is_enabled
(
   {cm@orig:component_status:PK}
)
CREATE TRIGGER TEMPLATE FOR cm@orig:component_status.is_enabled:{UPDATE}:
AFTER UPDATE ON {cm@orig:component_status}
BEGIN
   result = SELECT {cm@orig:component_status:PK},{cm@orig:component_status:is_enabled} FROM new INNER JOIN {cm@orig:component_status} where {NEW:PK}={cm@orig:component_status:PK} and new.is_enabled != {cm@orig:component_status.is_enabled}

   INSERT

END
