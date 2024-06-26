// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#include <aws/core/Aws.h>
#include <aws/elasticache/ElastiCacheClient.h>
#include <aws/elasticache/model/CreateCacheClusterRequest.h>
#include <aws/elasticache/model/CreateCacheClusterResult.h>
#include <iostream>

int main(int argc, char ** argv)
{
  if (argc != 5)
  {
    std::cout << "Usage: create_cache_cluster <cluster_id> <engine> <cache_node_type>"
                 "<num_cache_nodes>" << std::endl;
    return 1;
  }

  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    Aws::String cluster_id(argv[1]);
    Aws::String engine(argv[2]);
    Aws::String cache_node_type(argv[3]);
    auto num_cache_nodes = Aws::Utils::StringUtils::ConvertToInt32(argv[4]);

    Aws::ElastiCache::ElastiCacheClient elasticache;

    Aws::ElastiCache::Model::CreateCacheClusterRequest ccc_req;

    ccc_req.SetCacheClusterId(cluster_id);
    ccc_req.SetEngine(engine);
    ccc_req.SetCacheNodeType(cache_node_type);
    ccc_req.SetNumCacheNodes(num_cache_nodes);

    auto ccc_out = elasticache.CreateCacheCluster(ccc_req);

    if (ccc_out.IsSuccess())
    {
      std::cout << "Successfully created cache cluster" << std::endl;
    }
    else
    {
      std::cout << "Error creating cache cluster" << ccc_out.GetError().GetMessage()
        << std::endl;
    }
  }

  Aws::ShutdownAPI(options);
  return 0;
}
