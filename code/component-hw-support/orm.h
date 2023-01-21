// generated by /usr/local/bin/sqlpp11-ddl2cpp architecture/first-level/component-hw-support/HW.db-script.sql code/component-hw-support/orm model
#ifndef MODEL_ORM_H
#define MODEL_ORM_H

#include <sqlpp11/table.h>
#include <sqlpp11/data_types.h>
#include <sqlpp11/char_sequence.h>

namespace model
{
  namespace CPUInfo_
  {
    struct ProductId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productId;
            T& operator()() { return productId; }
            const T& operator()() const { return productId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Manufacturer
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "manufacturer";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T manufacturer;
            T& operator()() { return manufacturer; }
            const T& operator()() const { return manufacturer; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ModelName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "model_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T modelName;
            T& operator()() { return modelName; }
            const T& operator()() const { return modelName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ProductName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productName;
            T& operator()() { return productName; }
            const T& operator()() const { return productName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct Frequency
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "frequency";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T frequency;
            T& operator()() { return frequency; }
            const T& operator()() const { return frequency; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct CoreCount
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "core_count";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T coreCount;
            T& operator()() { return coreCount; }
            const T& operator()() const { return coreCount; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
  } // namespace CPUInfo_

  struct CPUInfo: sqlpp::table_t<CPUInfo,
               CPUInfo_::ProductId,
               CPUInfo_::Manufacturer,
               CPUInfo_::ModelName,
               CPUInfo_::ProductName,
               CPUInfo_::Frequency,
               CPUInfo_::CoreCount>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"CPUInfo\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T CPUInfo;
        T& operator()() { return CPUInfo; }
        const T& operator()() const { return CPUInfo; }
      };
    };
  };
  namespace Driver_
  {
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
    struct Description
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "description";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T description;
            T& operator()() { return description; }
            const T& operator()() const { return description; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
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
      using _traits = sqlpp::make_traits<sqlpp::boolean, sqlpp::tag::require_insert>;
    };
  } // namespace Driver_

  struct Driver: sqlpp::table_t<Driver,
               Driver_::HardwareId,
               Driver_::Name,
               Driver_::Description,
               Driver_::IsActive>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"Driver\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T Driver;
        T& operator()() { return Driver; }
        const T& operator()() const { return Driver; }
      };
    };
  };
  namespace GPUInfo_
  {
    struct ProductId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productId;
            T& operator()() { return productId; }
            const T& operator()() const { return productId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Manufacturer
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "manufacturer";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T manufacturer;
            T& operator()() { return manufacturer; }
            const T& operator()() const { return manufacturer; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ModelName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "model_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T modelName;
            T& operator()() { return modelName; }
            const T& operator()() const { return modelName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ProductName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productName;
            T& operator()() { return productName; }
            const T& operator()() const { return productName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct Frequency
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "frequency";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T frequency;
            T& operator()() { return frequency; }
            const T& operator()() const { return frequency; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct CoreCount
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "core_count";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T coreCount;
            T& operator()() { return coreCount; }
            const T& operator()() const { return coreCount; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct MemorySize
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "memory_size";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T memorySize;
            T& operator()() { return memorySize; }
            const T& operator()() const { return memorySize; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
  } // namespace GPUInfo_

  struct GPUInfo: sqlpp::table_t<GPUInfo,
               GPUInfo_::ProductId,
               GPUInfo_::Manufacturer,
               GPUInfo_::ModelName,
               GPUInfo_::ProductName,
               GPUInfo_::Frequency,
               GPUInfo_::CoreCount,
               GPUInfo_::MemorySize>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"GPUInfo\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T GPUInfo;
        T& operator()() { return GPUInfo; }
        const T& operator()() const { return GPUInfo; }
      };
    };
  };
  namespace HardwareInfo_
  {
    struct HardwareInfoId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "hardware_info_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T hardwareInfoId;
            T& operator()() { return hardwareInfoId; }
            const T& operator()() const { return hardwareInfoId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct DeviceModel
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "device_model";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T deviceModel;
            T& operator()() { return deviceModel; }
            const T& operator()() const { return deviceModel; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::can_be_null>;
    };
  } // namespace HardwareInfo_

  struct HardwareInfo: sqlpp::table_t<HardwareInfo,
               HardwareInfo_::HardwareInfoId,
               HardwareInfo_::DeviceModel>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"HardwareInfo\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T HardwareInfo;
        T& operator()() { return HardwareInfo; }
        const T& operator()() const { return HardwareInfo; }
      };
    };
  };
  namespace HardwareItem_
  {
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
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
    struct SerialNumber
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "serial_number";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T serialNumber;
            T& operator()() { return serialNumber; }
            const T& operator()() const { return serialNumber; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ProductId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productId;
            T& operator()() { return productId; }
            const T& operator()() const { return productId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct HardwareInfoId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "hardware_info_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T hardwareInfoId;
            T& operator()() { return hardwareInfoId; }
            const T& operator()() const { return hardwareInfoId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct ClassId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "class_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T classId;
            T& operator()() { return classId; }
            const T& operator()() const { return classId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
  } // namespace HardwareItem_

  struct HardwareItem: sqlpp::table_t<HardwareItem,
               HardwareItem_::HardwareId,
               HardwareItem_::SerialNumber,
               HardwareItem_::ProductId,
               HardwareItem_::HardwareInfoId,
               HardwareItem_::ClassId>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"HardwareItem\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T HardwareItem;
        T& operator()() { return HardwareItem; }
        const T& operator()() const { return HardwareItem; }
      };
    };
  };
  namespace HardwareItemClass_
  {
    struct ClassId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "class_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T classId;
            T& operator()() { return classId; }
            const T& operator()() const { return classId; }
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
    struct Description
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "description";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T description;
            T& operator()() { return description; }
            const T& operator()() const { return description; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
  } // namespace HardwareItemClass_

  struct HardwareItemClass: sqlpp::table_t<HardwareItemClass,
               HardwareItemClass_::ClassId,
               HardwareItemClass_::Name,
               HardwareItemClass_::Description>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"HardwareItemClass\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T HardwareItemClass;
        T& operator()() { return HardwareItemClass; }
        const T& operator()() const { return HardwareItemClass; }
      };
    };
  };
  namespace MemoryInfo_
  {
    struct ProductId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productId;
            T& operator()() { return productId; }
            const T& operator()() const { return productId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Manufacturer
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "manufacturer";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T manufacturer;
            T& operator()() { return manufacturer; }
            const T& operator()() const { return manufacturer; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ModelName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "model_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T modelName;
            T& operator()() { return modelName; }
            const T& operator()() const { return modelName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ProductName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productName;
            T& operator()() { return productName; }
            const T& operator()() const { return productName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct Capacity
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "capacity";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T capacity;
            T& operator()() { return capacity; }
            const T& operator()() const { return capacity; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Technology
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "technology";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T technology;
            T& operator()() { return technology; }
            const T& operator()() const { return technology; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Speed
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "speed";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T speed;
            T& operator()() { return speed; }
            const T& operator()() const { return speed; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
  } // namespace MemoryInfo_

  struct MemoryInfo: sqlpp::table_t<MemoryInfo,
               MemoryInfo_::ProductId,
               MemoryInfo_::Manufacturer,
               MemoryInfo_::ModelName,
               MemoryInfo_::ProductName,
               MemoryInfo_::Capacity,
               MemoryInfo_::Technology,
               MemoryInfo_::Speed>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"MemoryInfo\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T MemoryInfo;
        T& operator()() { return MemoryInfo; }
        const T& operator()() const { return MemoryInfo; }
      };
    };
  };
  namespace Product_
  {
    struct ProductId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productId;
            T& operator()() { return productId; }
            const T& operator()() const { return productId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::must_not_insert, sqlpp::tag::must_not_update>;
    };
  } // namespace Product_

  struct Product: sqlpp::table_t<Product,
               Product_::ProductId>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"Product\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T Product;
        T& operator()() { return Product; }
        const T& operator()() const { return Product; }
      };
    };
  };
  namespace StorageInfo_
  {
    struct ProductId
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_id";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productId;
            T& operator()() { return productId; }
            const T& operator()() const { return productId; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
    };
    struct Manufacturer
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "manufacturer";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T manufacturer;
            T& operator()() { return manufacturer; }
            const T& operator()() const { return manufacturer; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ModelName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "model_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T modelName;
            T& operator()() { return modelName; }
            const T& operator()() const { return modelName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct ProductName
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "product_name";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T productName;
            T& operator()() { return productName; }
            const T& operator()() const { return productName; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::text, sqlpp::tag::require_insert>;
    };
    struct Capacity
    {
      struct _alias_t
      {
        static constexpr const char _literal[] =  "capacity";
        using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
        template<typename T>
        struct _member_t
          {
            T capacity;
            T& operator()() { return capacity; }
            const T& operator()() const { return capacity; }
          };
      };
      using _traits = sqlpp::make_traits<sqlpp::integer, sqlpp::tag::require_insert>;
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
  } // namespace StorageInfo_

  struct StorageInfo: sqlpp::table_t<StorageInfo,
               StorageInfo_::ProductId,
               StorageInfo_::Manufacturer,
               StorageInfo_::ModelName,
               StorageInfo_::ProductName,
               StorageInfo_::Capacity,
               StorageInfo_::Type>
  {
    struct _alias_t
    {
      static constexpr const char _literal[] =  "\"StorageInfo\"";
      using _name_t = sqlpp::make_char_sequence<sizeof(_literal), _literal>;
      template<typename T>
      struct _member_t
      {
        T StorageInfo;
        T& operator()() { return StorageInfo; }
        const T& operator()() const { return StorageInfo; }
      };
    };
  };
} // namespace model
#endif