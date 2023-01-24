#include "install.h"
#include "json.hpp"
#include "storage/storage.h"
#include "storage/orm.h"

#include <sqlpp11/insert.h>

#include <fstream>
#include <iostream>
#include <chrono>

using json = nlohmann::json;

bool install_self()
{
   auto now = std::chrono::system_clock::now();
   model::Ecosystem ecosystem;
   model::SpaceRestrictionPolicy r_policy;
   model::StoragePolicy s_policy;
   std::cout << "Processing self-install\n";
   db(sqlpp::insert_into(r_policy).set(r_policy.uiName = "default", r_policy.createTime = now));
   auto result = db(select(r_policy.spaceRestrictionPolicyId).from(r_policy).unconditionally());
   auto result_id = result.begin()->spaceRestrictionPolicyId;
   std::cout << "Add spaceRestrictionPolicy with id=" << result_id << "\n";
   db(sqlpp::insert_into(s_policy).set(s_policy.spaceRestrictionPolicyId = result_id, s_policy.useSharedViews = true, s_policy.createTime = now));
   auto s_policy_id = db(select(s_policy.storagePolicyId).from(s_policy).unconditionally());
   db(sqlpp::insert_into(ecosystem).set(ecosystem.isActive = true, ecosystem.storagePolicyId = s_policy_id.begin()->storagePolicyId));
   return true;
}

bool install_all()
{
   connect_to_db();
   install_self();
   std::ifstream f("example.json");
   json data = json::parse(f);
   if (data.size() != 0)
   {
      std::cout << "Schema name is '" << data["object"]["developer"] << "@" << data["object"]["name"] << "'\n"
                << "Object version: " << data["object"]["version"] << "\n"
                                                                      "Object type: "
                << data["object"]["type"] << "\n";
      model::Manifest manifest;
      model::ManifestScheme mscheme = {};
      db(sqlpp::insert_into(mscheme).set(mscheme.fieldDescription = "{\"fields\":[\"1\",\"2\",\"etc...\"],\"desc\":\"default scheme\"}"));

      auto scheme_id = db(select(mscheme.schemeId).from(mscheme).unconditionally()).begin()->schemeId;
      std::string name = data["object"]["developer"].dump() + "@" + data["object"]["name"].dump();
      db(sqlpp::insert_into(manifest).set(manifest.hash = "0", manifest.schemeId = scheme_id, manifest.name = name, manifest.uiDescription = "", manifest.uiName = data["object"]["name"].dump(), manifest.version = data["object"]["version"].dump()));
      return true;
   }
   return false;
}
