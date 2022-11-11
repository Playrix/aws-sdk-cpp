﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/glue/Glue_EXPORTS.h>
#include <aws/glue/GlueRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/glue/model/CrawlerTargets.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/glue/model/SchemaChangePolicy.h>
#include <aws/glue/model/RecrawlPolicy.h>
#include <aws/glue/model/LineageConfiguration.h>
#include <aws/glue/model/LakeFormationConfiguration.h>
#include <aws/core/utils/memory/stl/AWSMap.h>
#include <utility>

namespace Aws
{
namespace Glue
{
namespace Model
{

  /**
   */
  class AWS_GLUE_API CreateCrawlerRequest : public GlueRequest
  {
  public:
    CreateCrawlerRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CreateCrawler"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>Name of the new crawler.</p>
     */
    inline const Aws::String& GetName() const{ return m_name; }

    /**
     * <p>Name of the new crawler.</p>
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * <p>Name of the new crawler.</p>
     */
    inline void SetName(const Aws::String& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>Name of the new crawler.</p>
     */
    inline void SetName(Aws::String&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * <p>Name of the new crawler.</p>
     */
    inline void SetName(const char* value) { m_nameHasBeenSet = true; m_name.assign(value); }

    /**
     * <p>Name of the new crawler.</p>
     */
    inline CreateCrawlerRequest& WithName(const Aws::String& value) { SetName(value); return *this;}

    /**
     * <p>Name of the new crawler.</p>
     */
    inline CreateCrawlerRequest& WithName(Aws::String&& value) { SetName(std::move(value)); return *this;}

    /**
     * <p>Name of the new crawler.</p>
     */
    inline CreateCrawlerRequest& WithName(const char* value) { SetName(value); return *this;}


    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline const Aws::String& GetRole() const{ return m_role; }

    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline bool RoleHasBeenSet() const { return m_roleHasBeenSet; }

    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline void SetRole(const Aws::String& value) { m_roleHasBeenSet = true; m_role = value; }

    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline void SetRole(Aws::String&& value) { m_roleHasBeenSet = true; m_role = std::move(value); }

    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline void SetRole(const char* value) { m_roleHasBeenSet = true; m_role.assign(value); }

    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline CreateCrawlerRequest& WithRole(const Aws::String& value) { SetRole(value); return *this;}

    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline CreateCrawlerRequest& WithRole(Aws::String&& value) { SetRole(std::move(value)); return *this;}

    /**
     * <p>The IAM role or Amazon Resource Name (ARN) of an IAM role used by the new
     * crawler to access customer resources.</p>
     */
    inline CreateCrawlerRequest& WithRole(const char* value) { SetRole(value); return *this;}


    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline const Aws::String& GetDatabaseName() const{ return m_databaseName; }

    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline bool DatabaseNameHasBeenSet() const { return m_databaseNameHasBeenSet; }

    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline void SetDatabaseName(const Aws::String& value) { m_databaseNameHasBeenSet = true; m_databaseName = value; }

    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline void SetDatabaseName(Aws::String&& value) { m_databaseNameHasBeenSet = true; m_databaseName = std::move(value); }

    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline void SetDatabaseName(const char* value) { m_databaseNameHasBeenSet = true; m_databaseName.assign(value); }

    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline CreateCrawlerRequest& WithDatabaseName(const Aws::String& value) { SetDatabaseName(value); return *this;}

    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline CreateCrawlerRequest& WithDatabaseName(Aws::String&& value) { SetDatabaseName(std::move(value)); return *this;}

    /**
     * <p>The Glue database where results are written, such as:
     * <code>arn:aws:daylight:us-east-1::database/sometable/ *</code>.</p>
     */
    inline CreateCrawlerRequest& WithDatabaseName(const char* value) { SetDatabaseName(value); return *this;}


    /**
     * <p>A description of the new crawler.</p>
     */
    inline const Aws::String& GetDescription() const{ return m_description; }

    /**
     * <p>A description of the new crawler.</p>
     */
    inline bool DescriptionHasBeenSet() const { return m_descriptionHasBeenSet; }

    /**
     * <p>A description of the new crawler.</p>
     */
    inline void SetDescription(const Aws::String& value) { m_descriptionHasBeenSet = true; m_description = value; }

    /**
     * <p>A description of the new crawler.</p>
     */
    inline void SetDescription(Aws::String&& value) { m_descriptionHasBeenSet = true; m_description = std::move(value); }

    /**
     * <p>A description of the new crawler.</p>
     */
    inline void SetDescription(const char* value) { m_descriptionHasBeenSet = true; m_description.assign(value); }

    /**
     * <p>A description of the new crawler.</p>
     */
    inline CreateCrawlerRequest& WithDescription(const Aws::String& value) { SetDescription(value); return *this;}

    /**
     * <p>A description of the new crawler.</p>
     */
    inline CreateCrawlerRequest& WithDescription(Aws::String&& value) { SetDescription(std::move(value)); return *this;}

    /**
     * <p>A description of the new crawler.</p>
     */
    inline CreateCrawlerRequest& WithDescription(const char* value) { SetDescription(value); return *this;}


    /**
     * <p>A list of collection of targets to crawl.</p>
     */
    inline const CrawlerTargets& GetTargets() const{ return m_targets; }

    /**
     * <p>A list of collection of targets to crawl.</p>
     */
    inline bool TargetsHasBeenSet() const { return m_targetsHasBeenSet; }

    /**
     * <p>A list of collection of targets to crawl.</p>
     */
    inline void SetTargets(const CrawlerTargets& value) { m_targetsHasBeenSet = true; m_targets = value; }

    /**
     * <p>A list of collection of targets to crawl.</p>
     */
    inline void SetTargets(CrawlerTargets&& value) { m_targetsHasBeenSet = true; m_targets = std::move(value); }

    /**
     * <p>A list of collection of targets to crawl.</p>
     */
    inline CreateCrawlerRequest& WithTargets(const CrawlerTargets& value) { SetTargets(value); return *this;}

    /**
     * <p>A list of collection of targets to crawl.</p>
     */
    inline CreateCrawlerRequest& WithTargets(CrawlerTargets&& value) { SetTargets(std::move(value)); return *this;}


    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline const Aws::String& GetSchedule() const{ return m_schedule; }

    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline bool ScheduleHasBeenSet() const { return m_scheduleHasBeenSet; }

    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline void SetSchedule(const Aws::String& value) { m_scheduleHasBeenSet = true; m_schedule = value; }

    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline void SetSchedule(Aws::String&& value) { m_scheduleHasBeenSet = true; m_schedule = std::move(value); }

    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline void SetSchedule(const char* value) { m_scheduleHasBeenSet = true; m_schedule.assign(value); }

    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline CreateCrawlerRequest& WithSchedule(const Aws::String& value) { SetSchedule(value); return *this;}

    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline CreateCrawlerRequest& WithSchedule(Aws::String&& value) { SetSchedule(std::move(value)); return *this;}

    /**
     * <p>A <code>cron</code> expression used to specify the schedule (see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-data-warehouse-schedule.html">Time-Based
     * Schedules for Jobs and Crawlers</a>. For example, to run something every day at
     * 12:15 UTC, you would specify: <code>cron(15 12 * * ? *)</code>.</p>
     */
    inline CreateCrawlerRequest& WithSchedule(const char* value) { SetSchedule(value); return *this;}


    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline const Aws::Vector<Aws::String>& GetClassifiers() const{ return m_classifiers; }

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline bool ClassifiersHasBeenSet() const { return m_classifiersHasBeenSet; }

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline void SetClassifiers(const Aws::Vector<Aws::String>& value) { m_classifiersHasBeenSet = true; m_classifiers = value; }

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline void SetClassifiers(Aws::Vector<Aws::String>&& value) { m_classifiersHasBeenSet = true; m_classifiers = std::move(value); }

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline CreateCrawlerRequest& WithClassifiers(const Aws::Vector<Aws::String>& value) { SetClassifiers(value); return *this;}

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline CreateCrawlerRequest& WithClassifiers(Aws::Vector<Aws::String>&& value) { SetClassifiers(std::move(value)); return *this;}

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline CreateCrawlerRequest& AddClassifiers(const Aws::String& value) { m_classifiersHasBeenSet = true; m_classifiers.push_back(value); return *this; }

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline CreateCrawlerRequest& AddClassifiers(Aws::String&& value) { m_classifiersHasBeenSet = true; m_classifiers.push_back(std::move(value)); return *this; }

    /**
     * <p>A list of custom classifiers that the user has registered. By default, all
     * built-in classifiers are included in a crawl, but these custom classifiers
     * always override the default classifiers for a given classification.</p>
     */
    inline CreateCrawlerRequest& AddClassifiers(const char* value) { m_classifiersHasBeenSet = true; m_classifiers.push_back(value); return *this; }


    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline const Aws::String& GetTablePrefix() const{ return m_tablePrefix; }

    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline bool TablePrefixHasBeenSet() const { return m_tablePrefixHasBeenSet; }

    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline void SetTablePrefix(const Aws::String& value) { m_tablePrefixHasBeenSet = true; m_tablePrefix = value; }

    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline void SetTablePrefix(Aws::String&& value) { m_tablePrefixHasBeenSet = true; m_tablePrefix = std::move(value); }

    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline void SetTablePrefix(const char* value) { m_tablePrefixHasBeenSet = true; m_tablePrefix.assign(value); }

    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline CreateCrawlerRequest& WithTablePrefix(const Aws::String& value) { SetTablePrefix(value); return *this;}

    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline CreateCrawlerRequest& WithTablePrefix(Aws::String&& value) { SetTablePrefix(std::move(value)); return *this;}

    /**
     * <p>The table prefix used for catalog tables that are created.</p>
     */
    inline CreateCrawlerRequest& WithTablePrefix(const char* value) { SetTablePrefix(value); return *this;}


    /**
     * <p>The policy for the crawler's update and deletion behavior.</p>
     */
    inline const SchemaChangePolicy& GetSchemaChangePolicy() const{ return m_schemaChangePolicy; }

    /**
     * <p>The policy for the crawler's update and deletion behavior.</p>
     */
    inline bool SchemaChangePolicyHasBeenSet() const { return m_schemaChangePolicyHasBeenSet; }

    /**
     * <p>The policy for the crawler's update and deletion behavior.</p>
     */
    inline void SetSchemaChangePolicy(const SchemaChangePolicy& value) { m_schemaChangePolicyHasBeenSet = true; m_schemaChangePolicy = value; }

    /**
     * <p>The policy for the crawler's update and deletion behavior.</p>
     */
    inline void SetSchemaChangePolicy(SchemaChangePolicy&& value) { m_schemaChangePolicyHasBeenSet = true; m_schemaChangePolicy = std::move(value); }

    /**
     * <p>The policy for the crawler's update and deletion behavior.</p>
     */
    inline CreateCrawlerRequest& WithSchemaChangePolicy(const SchemaChangePolicy& value) { SetSchemaChangePolicy(value); return *this;}

    /**
     * <p>The policy for the crawler's update and deletion behavior.</p>
     */
    inline CreateCrawlerRequest& WithSchemaChangePolicy(SchemaChangePolicy&& value) { SetSchemaChangePolicy(std::move(value)); return *this;}


    /**
     * <p>A policy that specifies whether to crawl the entire dataset again, or to
     * crawl only folders that were added since the last crawler run.</p>
     */
    inline const RecrawlPolicy& GetRecrawlPolicy() const{ return m_recrawlPolicy; }

    /**
     * <p>A policy that specifies whether to crawl the entire dataset again, or to
     * crawl only folders that were added since the last crawler run.</p>
     */
    inline bool RecrawlPolicyHasBeenSet() const { return m_recrawlPolicyHasBeenSet; }

    /**
     * <p>A policy that specifies whether to crawl the entire dataset again, or to
     * crawl only folders that were added since the last crawler run.</p>
     */
    inline void SetRecrawlPolicy(const RecrawlPolicy& value) { m_recrawlPolicyHasBeenSet = true; m_recrawlPolicy = value; }

    /**
     * <p>A policy that specifies whether to crawl the entire dataset again, or to
     * crawl only folders that were added since the last crawler run.</p>
     */
    inline void SetRecrawlPolicy(RecrawlPolicy&& value) { m_recrawlPolicyHasBeenSet = true; m_recrawlPolicy = std::move(value); }

    /**
     * <p>A policy that specifies whether to crawl the entire dataset again, or to
     * crawl only folders that were added since the last crawler run.</p>
     */
    inline CreateCrawlerRequest& WithRecrawlPolicy(const RecrawlPolicy& value) { SetRecrawlPolicy(value); return *this;}

    /**
     * <p>A policy that specifies whether to crawl the entire dataset again, or to
     * crawl only folders that were added since the last crawler run.</p>
     */
    inline CreateCrawlerRequest& WithRecrawlPolicy(RecrawlPolicy&& value) { SetRecrawlPolicy(std::move(value)); return *this;}


    /**
     * <p>Specifies data lineage configuration settings for the crawler.</p>
     */
    inline const LineageConfiguration& GetLineageConfiguration() const{ return m_lineageConfiguration; }

    /**
     * <p>Specifies data lineage configuration settings for the crawler.</p>
     */
    inline bool LineageConfigurationHasBeenSet() const { return m_lineageConfigurationHasBeenSet; }

    /**
     * <p>Specifies data lineage configuration settings for the crawler.</p>
     */
    inline void SetLineageConfiguration(const LineageConfiguration& value) { m_lineageConfigurationHasBeenSet = true; m_lineageConfiguration = value; }

    /**
     * <p>Specifies data lineage configuration settings for the crawler.</p>
     */
    inline void SetLineageConfiguration(LineageConfiguration&& value) { m_lineageConfigurationHasBeenSet = true; m_lineageConfiguration = std::move(value); }

    /**
     * <p>Specifies data lineage configuration settings for the crawler.</p>
     */
    inline CreateCrawlerRequest& WithLineageConfiguration(const LineageConfiguration& value) { SetLineageConfiguration(value); return *this;}

    /**
     * <p>Specifies data lineage configuration settings for the crawler.</p>
     */
    inline CreateCrawlerRequest& WithLineageConfiguration(LineageConfiguration&& value) { SetLineageConfiguration(std::move(value)); return *this;}


    /**
     * <p>Specifies Lake Formation configuration settings for the crawler.</p>
     */
    inline const LakeFormationConfiguration& GetLakeFormationConfiguration() const{ return m_lakeFormationConfiguration; }

    /**
     * <p>Specifies Lake Formation configuration settings for the crawler.</p>
     */
    inline bool LakeFormationConfigurationHasBeenSet() const { return m_lakeFormationConfigurationHasBeenSet; }

    /**
     * <p>Specifies Lake Formation configuration settings for the crawler.</p>
     */
    inline void SetLakeFormationConfiguration(const LakeFormationConfiguration& value) { m_lakeFormationConfigurationHasBeenSet = true; m_lakeFormationConfiguration = value; }

    /**
     * <p>Specifies Lake Formation configuration settings for the crawler.</p>
     */
    inline void SetLakeFormationConfiguration(LakeFormationConfiguration&& value) { m_lakeFormationConfigurationHasBeenSet = true; m_lakeFormationConfiguration = std::move(value); }

    /**
     * <p>Specifies Lake Formation configuration settings for the crawler.</p>
     */
    inline CreateCrawlerRequest& WithLakeFormationConfiguration(const LakeFormationConfiguration& value) { SetLakeFormationConfiguration(value); return *this;}

    /**
     * <p>Specifies Lake Formation configuration settings for the crawler.</p>
     */
    inline CreateCrawlerRequest& WithLakeFormationConfiguration(LakeFormationConfiguration&& value) { SetLakeFormationConfiguration(std::move(value)); return *this;}


    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline const Aws::String& GetConfiguration() const{ return m_configuration; }

    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline bool ConfigurationHasBeenSet() const { return m_configurationHasBeenSet; }

    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline void SetConfiguration(const Aws::String& value) { m_configurationHasBeenSet = true; m_configuration = value; }

    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline void SetConfiguration(Aws::String&& value) { m_configurationHasBeenSet = true; m_configuration = std::move(value); }

    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline void SetConfiguration(const char* value) { m_configurationHasBeenSet = true; m_configuration.assign(value); }

    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline CreateCrawlerRequest& WithConfiguration(const Aws::String& value) { SetConfiguration(value); return *this;}

    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline CreateCrawlerRequest& WithConfiguration(Aws::String&& value) { SetConfiguration(std::move(value)); return *this;}

    /**
     * <p>Crawler configuration information. This versioned JSON string allows users to
     * specify aspects of a crawler's behavior. For more information, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/crawler-configuration.html">Configuring
     * a Crawler</a>.</p>
     */
    inline CreateCrawlerRequest& WithConfiguration(const char* value) { SetConfiguration(value); return *this;}


    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline const Aws::String& GetCrawlerSecurityConfiguration() const{ return m_crawlerSecurityConfiguration; }

    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline bool CrawlerSecurityConfigurationHasBeenSet() const { return m_crawlerSecurityConfigurationHasBeenSet; }

    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline void SetCrawlerSecurityConfiguration(const Aws::String& value) { m_crawlerSecurityConfigurationHasBeenSet = true; m_crawlerSecurityConfiguration = value; }

    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline void SetCrawlerSecurityConfiguration(Aws::String&& value) { m_crawlerSecurityConfigurationHasBeenSet = true; m_crawlerSecurityConfiguration = std::move(value); }

    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline void SetCrawlerSecurityConfiguration(const char* value) { m_crawlerSecurityConfigurationHasBeenSet = true; m_crawlerSecurityConfiguration.assign(value); }

    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline CreateCrawlerRequest& WithCrawlerSecurityConfiguration(const Aws::String& value) { SetCrawlerSecurityConfiguration(value); return *this;}

    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline CreateCrawlerRequest& WithCrawlerSecurityConfiguration(Aws::String&& value) { SetCrawlerSecurityConfiguration(std::move(value)); return *this;}

    /**
     * <p>The name of the <code>SecurityConfiguration</code> structure to be used by
     * this crawler.</p>
     */
    inline CreateCrawlerRequest& WithCrawlerSecurityConfiguration(const char* value) { SetCrawlerSecurityConfiguration(value); return *this;}


    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline const Aws::Map<Aws::String, Aws::String>& GetTags() const{ return m_tags; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline bool TagsHasBeenSet() const { return m_tagsHasBeenSet; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline void SetTags(const Aws::Map<Aws::String, Aws::String>& value) { m_tagsHasBeenSet = true; m_tags = value; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline void SetTags(Aws::Map<Aws::String, Aws::String>&& value) { m_tagsHasBeenSet = true; m_tags = std::move(value); }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& WithTags(const Aws::Map<Aws::String, Aws::String>& value) { SetTags(value); return *this;}

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& WithTags(Aws::Map<Aws::String, Aws::String>&& value) { SetTags(std::move(value)); return *this;}

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& AddTags(const Aws::String& key, const Aws::String& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, value); return *this; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& AddTags(Aws::String&& key, const Aws::String& value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), value); return *this; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& AddTags(const Aws::String& key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, std::move(value)); return *this; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& AddTags(Aws::String&& key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), std::move(value)); return *this; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& AddTags(const char* key, Aws::String&& value) { m_tagsHasBeenSet = true; m_tags.emplace(key, std::move(value)); return *this; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& AddTags(Aws::String&& key, const char* value) { m_tagsHasBeenSet = true; m_tags.emplace(std::move(key), value); return *this; }

    /**
     * <p>The tags to use with this crawler request. You may use tags to limit access
     * to the crawler. For more information about tags in Glue, see <a
     * href="https://docs.aws.amazon.com/glue/latest/dg/monitor-tags.html">Amazon Web
     * Services Tags in Glue</a> in the developer guide.</p>
     */
    inline CreateCrawlerRequest& AddTags(const char* key, const char* value) { m_tagsHasBeenSet = true; m_tags.emplace(key, value); return *this; }

  private:

    Aws::String m_name;
    bool m_nameHasBeenSet = false;

    Aws::String m_role;
    bool m_roleHasBeenSet = false;

    Aws::String m_databaseName;
    bool m_databaseNameHasBeenSet = false;

    Aws::String m_description;
    bool m_descriptionHasBeenSet = false;

    CrawlerTargets m_targets;
    bool m_targetsHasBeenSet = false;

    Aws::String m_schedule;
    bool m_scheduleHasBeenSet = false;

    Aws::Vector<Aws::String> m_classifiers;
    bool m_classifiersHasBeenSet = false;

    Aws::String m_tablePrefix;
    bool m_tablePrefixHasBeenSet = false;

    SchemaChangePolicy m_schemaChangePolicy;
    bool m_schemaChangePolicyHasBeenSet = false;

    RecrawlPolicy m_recrawlPolicy;
    bool m_recrawlPolicyHasBeenSet = false;

    LineageConfiguration m_lineageConfiguration;
    bool m_lineageConfigurationHasBeenSet = false;

    LakeFormationConfiguration m_lakeFormationConfiguration;
    bool m_lakeFormationConfigurationHasBeenSet = false;

    Aws::String m_configuration;
    bool m_configurationHasBeenSet = false;

    Aws::String m_crawlerSecurityConfiguration;
    bool m_crawlerSecurityConfigurationHasBeenSet = false;

    Aws::Map<Aws::String, Aws::String> m_tags;
    bool m_tagsHasBeenSet = false;
  };

} // namespace Model
} // namespace Glue
} // namespace Aws
