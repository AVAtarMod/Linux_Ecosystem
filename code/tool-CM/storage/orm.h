// generated by /usr/local/bin/sqlpp11-ddl2cpp architecture/first-level/tool-CM/TCM.db-script.sql code/tool-CM/orm model
#ifndef MODEL_ORM_H
#define MODEL_ORM_H

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

namespace model
{
  namespace ExternalViewComponentInfo_
  {
    struct ComponentId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "component_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T componentId;
            T& operator()() { return componentId; }
            const T& operator()() const { return componentId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
  } // namespace ExternalViewComponentInfo_

  struct ExternalViewComponentInfo: sqlpp::table_t<ExternalViewComponentInfo,
               ExternalViewComponentInfo_::ComponentId>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"ExternalView_Component Info\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ExternalViewComponentInfo;
        T& operator()() { return ExternalViewComponentInfo; }
        const T& operator()() const { return ExternalViewComponentInfo; }
      };
    };
  };
  namespace ComponentStatus_
  {
    struct ComponentId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "component_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T componentId;
            T& operator()() { return componentId; }
            const T& operator()() const { return componentId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct IsEnabled
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "is_enabled";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T isEnabled;
            T& operator()() { return isEnabled; }
            const T& operator()() const { return isEnabled; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::boolean, sqlpp::tag::require_insert>;
    };
    struct Status
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "status";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T status;
            T& operator()() { return status; }
            const T& operator()() const { return status; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
  } // namespace ComponentStatus_

  struct ComponentStatus: sqlpp::table_t<ComponentStatus,
               ComponentStatus_::ComponentId,
               ComponentStatus_::IsEnabled,
               ComponentStatus_::Status>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"Component status\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ComponentStatus;
        T& operator()() { return ComponentStatus; }
        const T& operator()() const { return ComponentStatus; }
      };
    };
  };
  namespace ComponentDependency_
  {
    struct ComponentId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "component_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T componentId;
            T& operator()() { return componentId; }
            const T& operator()() const { return componentId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct DependencyId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "dependency_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T dependencyId;
            T& operator()() { return dependencyId; }
            const T& operator()() const { return dependencyId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct IsStrict
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "is_strict";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T isStrict;
            T& operator()() { return isStrict; }
            const T& operator()() const { return isStrict; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::boolean, sqlpp::tag::require_insert>;
    };
  } // namespace ComponentDependency_

  struct ComponentDependency: sqlpp::table_t<ComponentDependency,
               ComponentDependency_::ComponentId,
               ComponentDependency_::DependencyId,
               ComponentDependency_::IsStrict>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"Component dependency\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ComponentDependency;
        T& operator()() { return ComponentDependency; }
        const T& operator()() const { return ComponentDependency; }
      };
    };
  };
  namespace ComponentEndpoint_
  {
    struct EndpointId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "endpoint_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T endpointId;
            T& operator()() { return endpointId; }
            const T& operator()() const { return endpointId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct Name
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T name;
            T& operator()() { return name; }
            const T& operator()() const { return name; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ComponentId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "component_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T componentId;
            T& operator()() { return componentId; }
            const T& operator()() const { return componentId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
  } // namespace ComponentEndpoint_

  struct ComponentEndpoint: sqlpp::table_t<ComponentEndpoint,
               ComponentEndpoint_::EndpointId,
               ComponentEndpoint_::Name,
               ComponentEndpoint_::ComponentId>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"Component endpoint\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ComponentEndpoint;
        T& operator()() { return ComponentEndpoint; }
        const T& operator()() const { return ComponentEndpoint; }
      };
    };
  };
} // namespace model
#endif
