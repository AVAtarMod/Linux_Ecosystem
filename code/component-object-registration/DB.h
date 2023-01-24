// generated by ddl2cpp C:\Users\���\Desktop\DB.ddl C:\Database_Lab_v14\BD2022\sqlpp11-main\build\DB database
#ifndef DATABASE_DB_H
#define DATABASE_DB_H

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

namespace database
{
  namespace EcosystemUser_
  {
    struct UserId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "user_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T userId;
            T& operator()() { return userId; }
            const T& operator()() const { return userId; }
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
    struct Login
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "login";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T login;
            T& operator()() { return login; }
            const T& operator()() const { return login; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct Password
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "password";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T password;
            T& operator()() { return password; }
            const T& operator()() const { return password; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct Settings
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "settings";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T settings;
            T& operator()() { return settings; }
            const T& operator()() const { return settings; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text>;
    };
    struct LastSeenTime
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "last_seen_time";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T lastSeenTime;
            T& operator()() { return lastSeenTime; }
            const T& operator()() const { return lastSeenTime; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::time_point, sqlpp::tag::can_be_null>;
    };
    struct RegistrationTime
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "registration_time";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T registrationTime;
            T& operator()() { return registrationTime; }
            const T& operator()() const { return registrationTime; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::time_point>;
    };
  } // namespace EcosystemUser_

  struct EcosystemUser: sqlpp::table_t<EcosystemUser,
               EcosystemUser_::UserId,
               EcosystemUser_::Name,
               EcosystemUser_::Login,
               EcosystemUser_::Password,
               EcosystemUser_::Settings,
               EcosystemUser_::LastSeenTime,
               EcosystemUser_::RegistrationTime>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "ecosystem.\"User\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ecosystemUser;
        T& operator()() { return ecosystemUser; }
        const T& operator()() const { return ecosystemUser; }
      };
    };
  };
  namespace EcosystemDevice_
  {
    struct DeviceId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "device_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T deviceId;
            T& operator()() { return deviceId; }
            const T& operator()() const { return deviceId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct Type
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "type";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T type;
            T& operator()() { return type; }
            const T& operator()() const { return type; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct HardwareId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "hardware_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T hardwareId;
            T& operator()() { return hardwareId; }
            const T& operator()() const { return hardwareId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Settings
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "settings";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T settings;
            T& operator()() { return settings; }
            const T& operator()() const { return settings; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text>;
    };
    struct LastSeenTime
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "last_seen_time";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T lastSeenTime;
            T& operator()() { return lastSeenTime; }
            const T& operator()() const { return lastSeenTime; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::time_point, sqlpp::tag::can_be_null>;
    };
    struct RegistrationTime
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "registration_time";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T registrationTime;
            T& operator()() { return registrationTime; }
            const T& operator()() const { return registrationTime; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::time_point>;
    };
  } // namespace EcosystemDevice_

  struct EcosystemDevice: sqlpp::table_t<EcosystemDevice,
               EcosystemDevice_::DeviceId,
               EcosystemDevice_::Type,
               EcosystemDevice_::HardwareId,
               EcosystemDevice_::Settings,
               EcosystemDevice_::LastSeenTime,
               EcosystemDevice_::RegistrationTime>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "ecosystem.\"Device\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ecosystemDevice;
        T& operator()() { return ecosystemDevice; }
        const T& operator()() const { return ecosystemDevice; }
      };
    };
  };
  namespace EcosystemUserDevice_
  {
    struct DeviceId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "device_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T deviceId;
            T& operator()() { return deviceId; }
            const T& operator()() const { return deviceId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct UserId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "user_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T userId;
            T& operator()() { return userId; }
            const T& operator()() const { return userId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Settings
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "settings";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T settings;
            T& operator()() { return settings; }
            const T& operator()() const { return settings; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text>;
    };
    struct IsActive
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "is_active";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T isActive;
            T& operator()() { return isActive; }
            const T& operator()() const { return isActive; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::boolean>;
    };
  } // namespace EcosystemUserDevice_

  struct EcosystemUserDevice: sqlpp::table_t<EcosystemUserDevice,
               EcosystemUserDevice_::DeviceId,
               EcosystemUserDevice_::UserId,
               EcosystemUserDevice_::Settings,
               EcosystemUserDevice_::IsActive>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "ecosystem.\"User-Device\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ecosystemUserDevice;
        T& operator()() { return ecosystemUserDevice; }
        const T& operator()() const { return ecosystemUserDevice; }
      };
    };
  };
  namespace EcosystemStatisticalPlugin_
  {
    struct StatisticalPluginId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "statistical_plugin_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T statisticalPluginId;
            T& operator()() { return statisticalPluginId; }
            const T& operator()() const { return statisticalPluginId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct TimeInstall
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "time_install";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T timeInstall;
            T& operator()() { return timeInstall; }
            const T& operator()() const { return timeInstall; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::time_point>;
    };
    struct TimeUpdate
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "time_update";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T timeUpdate;
            T& operator()() { return timeUpdate; }
            const T& operator()() const { return timeUpdate; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::time_point, sqlpp::tag::can_be_null>;
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
  } // namespace EcosystemStatisticalPlugin_

  struct EcosystemStatisticalPlugin: sqlpp::table_t<EcosystemStatisticalPlugin,
               EcosystemStatisticalPlugin_::StatisticalPluginId,
               EcosystemStatisticalPlugin_::TimeInstall,
               EcosystemStatisticalPlugin_::TimeUpdate,
               EcosystemStatisticalPlugin_::Name>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "ecosystem.\"StatisticalPlugin\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T ecosystemStatisticalPlugin;
        T& operator()() { return ecosystemStatisticalPlugin; }
        const T& operator()() const { return ecosystemStatisticalPlugin; }
      };
    };
  };
} // namespace database
#endif