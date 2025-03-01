#ifndef SYMBIAN60

#ifndef UGEXPORTS_H
#define UGEXPORTS_H

// Shared library support
#ifdef WIN32
	#define UGEXPORT __declspec(dllexport)
	#define UGIMPORT __declspec(dllimport)
#else
#ifdef SYMBIAN60
	#define UGEXPORT __declspec(dllexport)
	#define UGIMPORT __declspec(dllimport)
#else
	#define UGEXPORT
	#define UGIMPORT
#endif
#endif

//为每个工程添加导入导出符

#ifdef STREAM_EXPORTS
	#define STREAM_API UGEXPORT
#else
	#define STREAM_API UGIMPORT
#endif

#ifdef COMPACTFILE_EXPORTS
#define COMPACTFILE_API UGEXPORT
#else
#define COMPACTFILE_API UGIMPORT
#endif

#ifdef TOOLKIT_EXPORTS
	#define TOOLKIT_API UGEXPORT
#else
	#define TOOLKIT_API UGIMPORT
#endif

#ifdef NETTOOLKIT_EXPORTS
	#define NETTOOLKIT_API UGEXPORT
#else
	#define NETTOOLKIT_API UGIMPORT
#endif

#ifdef BASE3D_EXPORTS
	#define BASE3D_API UGEXPORT
#else
	#define BASE3D_API UGIMPORT
#endif

//Add by zhangyk 01/03/2011
#ifdef PARTICLESYSTEM_EXPORTS
#define PARTICLESYSTEM_API UGEXPORT
#else 
#define PARTICLESYSTEM_API UGIMPORT 
#endif

#ifdef ALGORITHM_EXPORTS
	#define ALGORITHM_API UGEXPORT
#else
	#define ALGORITHM_API UGIMPORT
#endif

#ifdef COMPOUNDFILE_EXPORTS
	#define COMPOUNDFILE_API UGEXPORT
#else
	#define COMPOUNDFILE_API UGIMPORT
#endif

#ifdef CACHEBUILDER_EXPORTS
	#define CACHEBUILDER_API UGEXPORT
#else
	#define CACHEBUILDER_API UGIMPORT
#endif

#ifdef DATAEXCHANGE_EXPORTS
	#define DATAEXCHANGE_API UGEXPORT
#else
	#define DATAEXCHANGE_API UGIMPORT
#endif

#ifdef DATASETOPERATION_EXPORTS
	#define DATASETOPERATION_API UGEXPORT
#else
	#define DATASETOPERATION_API UGIMPORT
#endif

#ifdef SYMBOLEXCHANGE_EXPORTS
	#define SYMBOLEXCHANGE_API UGEXPORT
#else
	#define SYMBOLEXCHANGE_API UGIMPORT
#endif

#ifdef DRAWING_EXPORTS
	#define DRAWING_API UGEXPORT
#else
	#define DRAWING_API UGIMPORT
#endif

#ifdef DRAWINGCAD_EXPORTS
	#define DRAWINGCAD_API UGEXPORT
#else
	#define DRAWINGCAD_API UGIMPORT
#endif

#ifdef FILEPARSERMAPGIS_EXPORTS
#define FILEPARSERMAPGIS_API UGEXPORT
#else
#define FILEPARSERMAPGIS_API UGIMPORT
#endif

#ifdef DRAWING3D_EXPORTS
	#define DRAWING3D_API UGEXPORT
#else
	#define DRAWING3D_API UGIMPORT
#endif

#ifdef DRAWINGLAYOUT_EXPORTS
	#define DRAWINGLAYOUT_API UGEXPORT
#else
	#define DRAWINGLAYOUT_API UGIMPORT
#endif

#ifdef MAPEDITOR_EXPORTS
	#define MAPEDITOR_API UGEXPORT
#else
	#define MAPEDITOR_API UGIMPORT
#endif

#ifdef ENGINE_EXPORTS
	#define ENGINE_API UGEXPORT
#else
	#define ENGINE_API UGIMPORT
#endif

#ifdef ENGINEOGDC_EXPORTS
	#define ENGINEOGDC_API UGEXPORT
#else
	#define ENGINEOGDC_API UGIMPORT
#endif

#ifdef ENGINEEXTENDFILE_EXPORTS
	#define ENGINEEXTENDFILE_API UGEXPORT
#else
	#define ENGINEEXTENDFILE_API UGIMPORT
#endif

#ifdef ENGINEIMAGEPLUGIN_EXPORTS
	#define ENGINEIMAGEPLUGIN_API UGEXPORT
#else
	#define ENGINEIMAGEPLUGIN_API UGIMPORT
#endif

#ifdef ENGINESMCLOUD_EXPORTS
#define ENGINESMCLOUD_API UGEXPORT
#else
#define ENGINESMCLOUD_API UGIMPORT
#endif

#ifdef ENGINEMYSQL_EXPORTS
	#define ENGINEMYSQL_API UGEXPORT
#else
	#define ENGINEMYSQL_API UGIMPORT
#endif

#ifdef ENTERPRISEENGINE_EXPORTS
	#define ENTERPRISEENGINE_API UGEXPORT
#else
	#define ENTERPRISEENGINE_API UGIMPORT
#endif

#ifdef PLUGINSIT_EXPORTS
	#define PLUGINSIT_API UGEXPORT
#else
	#define PLUGINSIT_API UGIMPORT
#endif

#ifdef PLUGINSCV_EXPORTS
	#define  PLUGINSCV_API UGEXPORT
#else
	#define PLUGINSCV_API UGIMPORT
#endif

#ifdef PLUGINGDAL_EXPORTS
	#define PLUGINGDAL_API UGEXPORT
#else
	#define PLUGINGDAL_API UGIMPORT
#endif

#ifdef PLUGINMAPCACHE_EXPORTS
	#define PLUGINMAPCACHE_API UGEXPORT
#else
	#define PLUGINMAPCACHE_API UGIMPORT
#endif

#ifdef PLUGINMAPCACHE50_EXPORTS
	#define PLUGINMAPCACHE50_API UGEXPORT
#else
	#define PLUGINMAPCACHE50_API UGIMPORT
#endif

#ifdef PLUGINMAPCACHEV70_EXPORTS
#define PLUGINMAPCACHEV70_API UGEXPORT
#else
#define PLUGINMAPCACHEV70_API UGIMPORT
#endif

#ifdef CACHEFILE_EXPORTS
	#define CACHEFILE_API UGEXPORT
#else
	#define CACHEFILE_API UGIMPORT
#endif

#ifdef MAPSERVICESTUB_EXPORTS
#define MAPSERVICESTUB_API UGEXPORT
#else
#define MAPSERVICESTUB_API UGIMPORT
#endif

#ifdef PLUGINSMCLOUDSTUB_EXPORTS
#define PLUGINSMCLOUDSTUB_API UGEXPORT
#else
#define PLUGINSMCLOUDSTUB_API UGIMPORT
#endif

#ifdef PLUGINGOOGLEMAPSSTUB_EXPORTS
#define PLUGINGOOGLEMAPSSTUB_API UGEXPORT
#else
#define PLUGINGOOGLEMAPSSTUB_API UGIMPORT
#endif


#ifdef PLUGINMAPWORLDMAPSSTUB_EXPORTS
#define PLUGINMAPWORLDMAPSSTUB_API UGEXPORT
#else
#define PLUGINMAPWORLDMAPSSTUB_API UGIMPORT
#endif

#ifdef PLUGINRESTSTUB_EXPORTS
#define PLUGINRESTSTUB_API UGEXPORT
#else
#define PLUGINRESTSTUB_API UGIMPORT
#endif

#ifdef PLUGINOGCSTUB_EXPORTS
#define PLUGINOGCSTUB_API UGEXPORT
#else
#define PLUGINOGCSTUB_API UGIMPORT
#endif

#ifdef FILEPARSER_EXPORTS
#define FILEPARSER_API UGEXPORT
#else
#define FILEPARSER_API UGIMPORT
#endif

#ifdef FILEPARSERDEM_EXPORTS
#define FILEPARSERDEM_API UGEXPORT
#else
#define FILEPARSERDEM_API UGIMPORT
#endif

#ifdef FILEPARSERBGRID_EXPORTS
#define FILEPARSERBGRID_API UGEXPORT
#else
#define FILEPARSERBGRID_API UGIMPORT
#endif

#ifdef FILEPARSERLIDAR_EXPORTS
#define FILEPARSERLIDAR_API UGEXPORT
#else
#define FILEPARSERLIDAR_API UGIMPORT
#endif

#ifdef FILEPARSERHFA_EXPORTS
#define FILEPARSERHFA_API UGEXPORT
#else
#define FILEPARSERHFA_API UGIMPORT
#endif

#ifdef FILEPARSERRAW_EXPORTS
#define FILEPARSERRAW_API UGEXPORT
#else
#define FILEPARSERRAW_API UGIMPORT
#endif

#ifdef FILEPARSERSHAPE_EXPORTS
	#define FILEPARSERSHAPE_API UGEXPORT
#else
	#define FILEPARSERSHAPE_API UGIMPORT
#endif

#ifdef FILEPARSERGRID_EXPORTS
	#define FILEPARSERGRID_API UGEXPORT
#else
	#define FILEPARSERGRID_API UGIMPORT
#endif


#ifdef FILEPARSERSTET_EXPORTS
#define FILEPARSERSTET_API UGEXPORT
#else
#define FILEPARSERSTET_API UGIMPORT
#endif


#ifdef FILEPARSERACAD_EXPORTS
	#define FILEPARSERACAD_API UGEXPORT
#else
	#define FILEPARSERACAD_API UGIMPORT
#endif


#ifdef FILEPARSER3DS_EXPORTS
	#define FILEPARSER3DS_API UGEXPORT
#else
	#define FILEPARSER3DS_API UGIMPORT
#endif

#ifdef FILEPARSER3DMODEL_EXPORTS
#define FILEPARSER3DMODEL_API UGEXPORT
#else
#define FILEPARSER3DMODEL_API UGIMPORT
#endif

#ifdef FILEPARSERSGM_EXPORTS
#define FILEPARSERSGM_API UGEXPORT
#else
#define FILEPARSERSGM_API UGIMPORT
#endif

#ifdef FILEPARSERFME_EXPORTS
#define FILEPARSERFME_API UGEXPORT
#else
#define FILEPARSERFME_API UGIMPORT
#endif

#ifdef FILEPARSERESRI_EXPORTS
#define FILEPARSERESRI_API UGEXPORT
#else
#define FILEPARSERESRI_API UGIMPORT
#endif



#ifdef GEOMETRY_EXPORTS
	#define GEOMETRY_API UGEXPORT
#else
	#define GEOMETRY_API UGIMPORT
#endif

#ifdef GEOMETRY3D_EXPORTS
	#define GEOMETRY3D_API UGEXPORT
#else
	#define GEOMETRY3D_API UGIMPORT
#endif

#ifdef GEOMETRYCAD_EXPORTS
	#define GEOMETRYCAD_API UGEXPORT
#else
	#define GEOMETRYCAD_API UGIMPORT
#endif

#ifdef GEOMETRYLAYOUT_EXPORTS
	#define GEOMETRYLAYOUT_API UGEXPORT
#else
	#define GEOMETRYLAYOUT_API UGIMPORT
#endif

#ifdef GEOMETRY3D_EXPORTS
	#define GEOMETRY3D_API UGEXPORT
#else
	#define GEOMETRY3D_API UGIMPORT
#endif

#ifdef GEOOPERATION_EXPORTS
	#define GEOOPERATION_API UGEXPORT
#else
	#define GEOOPERATION_API UGIMPORT
#endif

#ifdef GRAPHICS_EXPORTS
	#define GRAPHICS_API UGEXPORT
#else
	#define GRAPHICS_API UGIMPORT
#endif

#ifdef RECTIFY_EXPORTS
	#define RECTIFY_API UGEXPORT
#else
	#define RECTIFY_API UGIMPORT
#endif

#ifdef SHEETJOIN_EXPORTS
	#define SHEETJOIN_API UGEXPORT
#else
	#define SHEETJOIN_API UGIMPORT
#endif

#ifdef IMAGEANALYST_EXPORTS
	#define IMAGEANALYST_API UGEXPORT
#else
	#define IMAGEANALYST_API UGIMPORT
#endif

#ifdef GRIDANALYST_EXPORTS
	#define GRIDANALYST_API UGEXPORT
#else
	#define GRIDANALYST_API UGIMPORT
#endif

#ifdef GRIDMODELING_EXPORTS
#define GRIDMODELING_API UGEXPORT
#else
#define GRIDMODELING_API UGIMPORT
#endif

#ifdef LAYOUT_EXPORTS
	#define LAYOUT_API UGEXPORT
#else
	#define LAYOUT_API UGIMPORT
#endif

#ifdef LAYOUTEDITOR_EXPORTS
	#define LAYOUTEDITOR_API UGEXPORT
#else
	#define LAYOUTEDITOR_API UGIMPORT
#endif

#ifdef LICENSE_EXPORTS
	#define LICENSE_API UGEXPORT
#else
	#define LICENSE_API UGIMPORT
#endif

#ifdef MAP_EXPORTS
	#define MAP_API UGEXPORT
#else
	#define MAP_API UGIMPORT
#endif

#ifdef MAPWINDOW_EXPORTS
	#define MAPWINDOW_API UGEXPORT
#else
	#define MAPWINDOW_API UGIMPORT
#endif

#ifdef MAPBORDER_EXPORTS
	#define MAPBORDER_API UGEXPORT
#else
	#define MAPBORDER_API UGIMPORT
#endif

#ifdef THEMEBASE_EXPORTS
	#define THEMEBASE_API UGEXPORT
#else
	#define THEMEBASE_API UGIMPORT
#endif

#ifdef THEMEADVANCE_EXPORTS
	#define THEMEADVANCE_API UGEXPORT
#else
	#define THEMEADVANCE_API UGIMPORT
#endif

#ifdef THEME3DBASE_EXPORTS
	#define THEME3DBASE_API UGEXPORT
#else
	#define THEME3DBASE_API UGIMPORT
#endif

#ifdef METADATA_EXPORTS
#define METADATA_API UGEXPORT
#else
#define METADATA_API UGIMPORT
#endif

#ifdef NETWORKBUILDER_EXPORTS
	#define NETWORKBUILDER_API UGEXPORT
#else
	#define NETWORKBUILDER_API UGIMPORT
#endif

#ifdef NETWORKENVIRONMENT_EXPORTS
	#define NETWORKENVIRONMENT_API UGEXPORT
#else
	#define NETWORKENVIRONMENT_API UGIMPORT
#endif

#ifdef GEOMETRICNETWORK_EXPORTS
#define GEOMETRICNETWORK_API UGEXPORT
#else
#define GEOMETRICNETWORK_API UGIMPORT
#endif

#ifdef PUBLICTRANSPORT_EXPORTS
#define PUBLICTRANSPORT_API UGEXPORT
#else
#define PUBLICTRANSPORT_API UGIMPORT
#endif

#ifdef PATHANALYST_EXPORTS
	#define PATHANALYST_API UGEXPORT
#else
	#define PATHANALYST_API UGIMPORT
#endif

#ifdef LOGISTICS_EXPORTS
	#define LOGISTICS_API UGEXPORT
#else
	#define LOGISTICS_API UGIMPORT
#endif

#ifdef ALLOCATION_EXPORTS
	#define ALLOCATION_API UGEXPORT
#else
	#define ALLOCATION_API UGIMPORT
#endif

#ifdef NETWORKANALYST_EXPORTS
	#define NETWORKANALYST_API UGEXPORT
#else
	#define NETWORKANALYST_API UGIMPORT
#endif

#ifdef GEOCODE_EXPORTS
	#define GEOCODE_API UGEXPORT
#else
	#define GEOCODE_API UGIMPORT
#endif

#ifdef OPERATION_EXPORTS
#define OPERATION_API UGEXPORT
#else
#define OPERATION_API UGIMPORT
#endif

#ifdef OVERLAY_EXPORTS
#define OVERLAY_API UGEXPORT
#else
#define OVERLAY_API UGIMPORT
#endif

#ifdef PROXIMITY_EXPORTS
#define PROXIMITY_API UGEXPORT
#else
#define PROXIMITY_API UGIMPORT
#endif

#ifdef GENERALIZATION_EXPORTS
#define GENERALIZATION_API UGEXPORT
#else
#define GENERALIZATION_API UGIMPORT
#endif

#ifdef ENGINESDBPLUS_EXPORTS
	#define SDBPLUSENGINE_API UGEXPORT
#else
	#define SDBPLUSENGINE_API UGIMPORT
#endif


#ifdef ORCENGINE_EXPORTS
	#define ORCENGINE_API UGEXPORT
#else
	#define ORCENGINE_API UGIMPORT
#endif

#ifdef ENGINEPG_EXPORTS
	#define ENGINEPG_API UGEXPORT
#else
	#define ENGINEPG_API UGIMPORT
#endif

#ifdef OSPENGINE_EXPORTS
#define OSPENGINE_API UGEXPORT
#else
#define OSPENGINE_API UGIMPORT
#endif

#ifdef UDBENGINE_EXPORTS
	#define UDBENGINE_API UGEXPORT
#else
	#define UDBENGINE_API UGIMPORT
#endif

#ifdef PROJECTION_EXPORTS
	#define PROJECTION_API UGEXPORT
#else
	#define PROJECTION_API UGIMPORT
#endif

#ifdef ENGINEOGC_EXPORTS
	#define ENGINEOGC_API UGEXPORT
#else
	#define ENGINEOGC_API UGIMPORT
#endif

#ifdef ENGINEGOOGLEMAPS_EXPORTS
#define ENGINEGOOGLEMAPS_API UGEXPORT
#else
#define ENGINEGOOGLEMAPS_API UGIMPORT
#endif

#ifdef  ENGINEBAIDUMAPS_EXPORTS
#define ENGINEBAIDUMAPS_API UGEXPORT
#else
#define ENGINEBAIDUMAPS_API UGIMPORT
#endif

#ifdef  ENGINESCV_EXPORTS
#define ENGINESCV_API UGEXPORT
#else
#define ENGINESCV_API UGIMPORT
#endif

#ifdef  ENGINEOPENSTREETMAPS_EXPORTS
#define ENGINEOPENSTREETMAPS_API UGEXPORT
#else
#define ENGINEOPENSTREETMAPS_API UGIMPORT
#endif

#ifdef ENGINEMAPWORLDMAPS_EXPORTS
#define ENGINEMapWorldMAPS_API UGEXPORT
#else
#define ENGINEMapWorldMAPS_API UGIMPORT
#endif

#ifdef ENGINEREST_EXPORTS
#define ENGINEREST_API UGEXPORT
#else
#define ENGINEREST_API UGIMPORT
#endif

#ifdef ENGINEDM_EXPORTS
#define ENGINEDM_API UGEXPORT
#else
#define ENGINEDM_API UGIMPORT
#endif

#ifdef OGCPARSER_EXPORTS
#define OGCPARSER_API UGEXPORT
#else
#define OGCPARSER_API UGIMPORT
#endif

#ifdef INFORMIXENGINE_EXPORTS
#define INFORMIXENGINE_API UGEXPORT
#else
#define INFORMIXENGINE_API UGIMPORT
#endif

#ifdef SYMBOL_EXPORTS
	#define SYMBOL_API UGEXPORT
#else
	#define SYMBOL_API UGIMPORT
#endif

#ifdef SYMBOLMARKER_EXPORTS
	#define SYMBOLMARKER_API UGEXPORT
#else
	#define SYMBOLMARKER_API UGIMPORT
#endif

#ifdef SYMBOLMARKER3D_EXPORTS
	#define SYMBOLMARKER3D_API UGEXPORT
#else
	#define SYMBOLMARKER3D_API UGIMPORT
#endif

#ifdef SYMBOLLINE_EXPORTS
	#define SYMBOLLINE_API UGEXPORT
#else
	#define SYMBOLLINE_API UGIMPORT
#endif

#ifdef SYMBOLFILL_EXPORTS
	#define SYMBOLFILL_API UGEXPORT
#else
	#define SYMBOLFILL_API UGIMPORT
#endif

#ifdef SYMBOLRULE_EXPORTS
	#define SYMBOLRULE_API UGEXPORT
#else
	#define SYMBOLRULE_API UGIMPORT
#endif

#ifdef TABLE_EXPORTS
	#define TABLE_API UGEXPORT
#else
	#define TABLE_API UGIMPORT
#endif

#ifdef SQLITECI_EXPORTS
	#define SQLITECI_API UGEXPORT
#else
	#define SQLITECI_API UGIMPORT
#endif

#ifdef MYSQLCI_EXPORTS
	#define MYSQLCI_API UGEXPORT
#else
	#define MYSQLCI_API UGIMPORT
#endif

#ifdef PGSQLCI_EXPORTS
	#define PGSQLCI_API	UGEXPORT
#else
	#define PGSQLCI_API	UGIMPORT
#endif

#ifdef ORACLECI_EXPORTS
	#define ORACLECI_API UGEXPORT
#else
	#define ORACLECI_API UGIMPORT
#endif

#ifdef ODBCCI_EXPORTS
	#define ODBCCI_API UGEXPORT
#else
	#define ODBCCI_API UGIMPORT
#endif

#ifdef DMCI_EXPORTS
#define DMCI_API UGEXPORT
#else
#define DMCI_API UGIMPORT
#endif

#ifdef DMCIENGINE_EXPORTS
#define DMCIENGINE_API UGEXPORT
#else
#define DMCIENGINE_API UGIMPORT
#endif

#ifdef TOPOLOGY_EXPORTS
#define TOPOLOGY_API UGEXPORT
#else
#define TOPOLOGY_API UGIMPORT
#endif

#ifdef DATACHECK_EXPORTS
#define DATACHECK_API UGEXPORT
#else
#define DATACHECK_API UGIMPORT
#endif

#ifdef TOPOBASE_EXPORTS
	#define TOPOBASE_API UGEXPORT
#else
	#define TOPOBASE_API UGIMPORT
#endif

#ifdef TOPOBUILDER_EXPORTS
	#define TOPOBUILDER_API UGEXPORT
#else
	#define TOPOBUILDER_API UGIMPORT
#endif

#ifdef SPATIALQUERY_EXPORTS
#define SPATIALQUERY_API UGEXPORT
#else
#define SPATIALQUERY_API UGIMPORT
#endif

#ifdef GRAPHICSU_EXPORTS
	#define GRAPHICSU_API UGEXPORT
#else
	#define GRAPHICSU_API UGIMPORT
#endif

#ifdef GRAPHICSW_EXPORTS
	#define GRAPHICSW_API UGEXPORT
#else
	#define GRAPHICSW_API UGIMPORT
#endif

#ifdef GRAPHICSPDF_EXPORTS
	#define GRAPHICSPDF_API UGEXPORT
#else
	#define GRAPHICSPDF_API UGIMPORT
#endif

//star Add tangzq in 20081-12-19
#ifdef GRAPHICSXPS_EXPORTS
#define GRAPHICSXPS_API UGEXPORT
#else
#define GRAPHICSXPS_API UGIMPORT
#endif
//end Add tangzq in 20081-12-19

#ifdef GRAPHICSQT_EXPORTS
	#define GRAPHICSQT_API UGEXPORT
#else
	#define GRAPHICSQT_API UGIMPORT
#endif

#ifdef GRAPHICSMINIGUI_EXPORTS
	#define GRAPHICSMINIGUI_API UGEXPORT
#else
	#define GRAPHICSMINIGUI_API UGIMPORT
#endif

#ifdef GRAPHICSPS_EXPORTS
	#define GRAPHICSPS_API UGEXPORT
#else
	#define GRAPHICSPS_API UGIMPORT
#endif

#ifdef GRAPHICSMEM_EXPORTS
#define GRAPHICSMEM_API UGEXPORT
#else
#define GRAPHICSMEM_API UGIMPORT
#endif

#ifdef WORKSPACE_EXPORTS
	#define WORKSPACE_API UGEXPORT
#else
	#define WORKSPACE_API UGIMPORT
#endif

#ifdef GRAPHICSX_EXPORTS
	#define GRAPHICSX_API UGEXPORT
#else
	#define GRAPHICSX_API UGIMPORT
#endif

//3D-related projects
#ifdef DRAWING3D_EXPORTS
#define DRAWING3D_API UGEXPORT
#else
#define DRAWING3D_API UGIMPORT
#endif

#ifdef EDITOR3D_EXPORTS
#define EDITOR3D_API UGEXPORT
#else
#define EDITOR3D_API UGIMPORT
#endif

#ifdef SYMBOL3D_EXPORTS
#define SYMBOL3D_API UGEXPORT
#else
#define SYMBOL3D_API UGIMPORT
#endif

#ifdef GRAPHICS3D_EXPORTS
#define GRAPHICS3D_API UGEXPORT
#else 
#define GRAPHICS3D_API UGIMPORT 
#endif

#ifdef GRAPHICS3DGL_EXPORTS
#define GRAPHICS3DGL_API UGEXPORT
#else 
#define GRAPHICS3DGL_API UGIMPORT 
#endif

#ifdef GRAPHICS3DDX_EXPORTS
#define GRAPHICS3DDX_API UGEXPORT
#else 
#define GRAPHICS3DDX_API UGIMPORT 
#endif

#ifdef GRAPHICS3DOGRE_EXPORTS
#define GRAPHICS3DOGRE_API UGEXPORT
#else 
#define GRAPHICS3DOGRE_API UGIMPORT 
#endif

#ifdef RENDER_EXPORTS
#define RENDER_API UGEXPORT
#else 
#define RENDER_API UGIMPORT 
#endif

#ifdef SCENE_EXPORTS
#define SCENE_API UGEXPORT
#else 
#define SCENE_API UGIMPORT 
#endif

#ifdef SCENEEDITOR_EXPORTS
#define SCENEEDITOR_API UGEXPORT
#else 
#define SCENEEDITOR_API UGIMPORT 
#endif

#ifdef LAYER3DDATASET_EXPORTS
#define LAYER3DDATASET_API UGEXPORT
#else 
#define LAYER3DDATASET_API UGIMPORT 
#endif

#ifdef LAYER3DFILE_EXPORTS
#define LAYER3DFILE_API UGEXPORT
#else 
#define LAYER3DFILE_API UGIMPORT 
#endif

#ifdef LAYER3DTREE_EXPORTS
#define LAYER3DTREE_API UGEXPORT
#else 
#define LAYER3DTREE_API UGIMPORT 
#endif

#ifdef LAYERGEIMAGE_EXPORTS
#define LAYERGEIMAGE_API UGEXPORT
#else 
#define LAYERGEIMAGE_API UGIMPORT 
#endif

#ifdef SDEENGINE_EXPORTS
	#define SDEENGINE_API UGEXPORT
#else
	#define SDEENGINE_API UGIMPORT
#endif


#ifdef DB2ENGINE_EXPORTS
#define DB2ENGINE_API UGEXPORT
#else
#define DB2ENGINE_API UGIMPORT
#endif

#ifdef SQLENGINE_EXPORTS
#define SQLENGINE_API UGEXPORT
#else
#define SQLENGINE_API UGIMPORT
#endif

#ifdef KINGENGINE_EXPORTS
#define KINGENGINE_API UGEXPORT
#else
#define KINGENGINE_API UGIMPORT
#endif

#ifdef MEMENGINE_EXPORTS
#define MEMENGINE_API UGEXPORT
#else
#define MEMENGINE_API UGIMPORT
#endif

#ifdef BUILDER3D_EXPORTS
#define BUILDER3D_API UGEXPORT
#else
#define BUILDER3D_API UGIMPORT
#endif

#ifdef SPATIALINDEX_EXPORTS
#define SPATIALINDEX_API UGEXPORT
#else
#define SPATIALINDEX_API UGIMPORT
#endif

#ifdef FILEPARSEROGR_EXPORTS
#define FILEPARSEROGR_API UGEXPORT
#else
#define FILEPARSEROGR_API UGIMPORT
#endif

#ifdef FILEPARSERGDAL_EXPORTS
#define FILEPARSERGDAL_API UGEXPORT
#else
#define FILEPARSERGDAL_API UGIMPORT
#endif

#ifdef FILEPARSERPNG_EXPORTS
#define FILEPARSERPNG_API UGEXPORT
#else
#define FILEPARSERPNG_API UGIMPORT
#endif

#ifdef FILEPARSERAIGRID_EXPORTS
#define FILEPARSERAIGRID_API UGEXPORT
#else
#define FILEPARSERAIGRID_API UGIMPORT
#endif

#ifdef FILEPARSERCSV_EXPORTS
#define FILEPARSERCSV_API UGEXPORT
#else
#define FILEPARSERCSV_API UGIMPORT
#endif

#ifdef FILEPARSERSCV_EXPORTS
#define FILEPARSERSCV_API UGEXPORT
#else
#define FILEPARSERSCV_API UGIMPORT
#endif

#ifdef FILEPARSERGTIFF_EXPORTS
	#define FILEPARSERGTIFF_API UGEXPORT
#else
	#define FILEPARSERGTIFF_API UGIMPORT
#endif

#ifdef FILEPARSERMITAB_EXPORTS
#define FILEPARSERMITAB_API UGEXPORT
#else
#define FILEPARSERMITAB_API UGIMPORT
#endif

#ifdef FILEPARSERENC_EXPORTS
#define FILEPARSERENC_API UGEXPORT
#else
#define FILEPARSERENC_API UGIMPORT
#endif

#ifdef  FILEPARSERTEMS_EXPORTS
#define FILEPARSERTEMS_API UGEXPORT
#else
#define FILEPARSERTEMS_API UGIMPORT
#endif

#ifdef FILEPARSERKML_EXPORTS
#define FILEPARSERKML_API UGEXPORT
#else
#define FILEPARSERKML_API UGIMPORT
#endif

#ifdef MAPWINDOW_EXPORTS
#define MAPWINDOW_API UGEXPORT
#else
#define MAPWINDOW_API UGIMPORT
#endif

#ifdef MAPEDITOR_EXPORTS
#define MAPEDITOR_API UGEXPORT
#else
#define MAPEDITOR_API UGIMPORT
#endif

#ifdef REPRESENTATION_EXPORTS
#define REPRESENTATION_API UGEXPORT
#else
#define REPRESENTATION_API UGIMPORT
#endif

#ifdef DB2CI_EXPORTS
#define DB2CI_API UGEXPORT
#else
#define DB2CI_API UGIMPORT
#endif

#ifdef INFORMIXCI_EXPORTS
#define INFORMIXCI_API UGEXPORT
#else
#define INFORMIXCI_API UGIMPORT
#endif

#ifdef COMPOUNDFILE64_EXPORTS
#define COMPOUNDFILE64_API UGEXPORT
#else
#define COMPOUNDFILE64_API UGIMPORT
#endif

#ifdef ENGINEUDB_EXPORTS
#define ENGINEUDB_API UGEXPORT
#else
#define ENGINEUDB_API UGIMPORT
#endif

#ifdef ENGINEINFORMIX_EXPORTS
#define ENGINEINFORMIX_API UGEXPORT
#else
#define ENGINEINFORMIX_API UGIMPORT
#endif

#ifdef KMLGENERATOR_EXPORTS
#define KMLGENERATOR_API UGEXPORT
#else
#define KMLGENERATOR_API UGIMPORT
#endif

#ifdef INTERNATIONALICU_EXPORTS
#define INTERNATIONALICU_API UGEXPORT
#else
#define INTERNATIONALICU_API UGIMPORT
#endif

#ifdef PLUGINGLOBALCACHE_EXPORTS
#define PLUGINGLOBALCACHE_API UGEXPORT
#else
#define PLUGINGLOBALCACHE_API UGIMPORT
#endif

#ifdef PLUGINGRIDCACHE_EXPORTS
#define PLUGINGRIDCACHE_API UGEXPORT
#else
#define PLUGINGRIDCACHE_API UGIMPORT
#endif

#ifdef PLUGINGECACHE_EXPORTS
#define PLUGINGECACHE_API UGEXPORT
#else
#define PLUGINGECACHE_API UGIMPORT
#endif

#ifdef PLUGINWEBCACHE_EXPORTS
#define PLUGINWEBCACHE_API UGEXPORT
#else
#define PLUGINWEBCACHE_API UGIMPORT
#endif

#ifdef REMOTESENSINGANALYST_EXPORTS
#define REMOTESENSINGANALYST_API UGEXPORT
#else
#define REMOTESENSINGANALYST_API UGIMPORT
#endif

#ifdef LAYER3DMAP_EXPORTS
#define LAYER3DMAP_API UGEXPORT
#else
#define LAYER3DMAP_API UGIMPORT
#endif

#ifdef PROCESSMODELING_EXPORTS
	#define PROCESSMODELING_API UGEXPORT
#else
	#define PROCESSMODELING_API UGIMPORT
#endif

#ifdef PROCESSFUNCTION_EXPORTS
	#define PROCESSFUNCTION_API UGEXPORT
#else
	#define PROCESSFUNCTION_API UGIMPORT
#endif

#ifdef FILEPARSERCOMMON_EXPORTS
#define FILEPARSERCOMMON_API UGEXPORT
#else
#define FILEPARSERCOMMON_API UGIMPORT
#endif

#ifdef PLUGINCOMMON_EXPORTS
#define PLUGINCOMMON_API UGEXPORT
#else
#define PLUGINCOMMON_API UGIMPORT
#endif

#ifdef PLUGINECW_EXPORTS
#define PLUGINECW_API UGEXPORT
#else
#define PLUGINECW_API UGIMPORT
#endif

//  [added by zhangshuo at 1/12/2010]
#ifdef ENGINENETCDF_EXPORTS
#define ENGINENETCDF_API UGEXPORT
#else
#define ENGINENETCDF_API UGIMPORT
#endif
//  [added by zhangshuo at 1/12/2010]

//  [added by zengwh at 4/13/2010]
#ifdef UNIVERSALCI_EXPORTS
#define UNIVERSALCI_API UGEXPORT
#else
#define UNIVERSALCI_API UGIMPORT
#endif

#ifdef UODBCCI_EXPORTS
#define UODBCCI_API UGEXPORT
#else
#define UODBCCI_API UGIMPORT
#endif

#ifdef UORACLECI_EXPORTS
#define UORACLECI_API UGEXPORT
#else
#define UORACLECI_API UGIMPORT
#endif

//  [added by zengwh at 4/13/2010]

//  [added by zengwh at 6/11/2010]
#ifdef DATARECOVERY_EXPORTS
#define DATARECOVERY_API UGEXPORT
#else
#define DATARECOVERY_API UGIMPORT
#endif
//  [added by zengwh at 6/11/2010]

#ifdef GRAPHICSMEM_EXPORTS
#define GRAPHICSMEM_API UGEXPORT
#else
#define GRAPHICSMEM_API UGIMPORT
#endif

//  [add by yangbiao at 6/9/2011]

#ifdef ENGINEPCI_EXPORTS
#define ENGINEPCI_API UGEXPORT
#else
#define ENGINEPCI_API UGIMPORT
#endif

//  [add by yangbiao at 6/9/2011]

#ifdef CHARTBASE_EXPORTS
#define CHARTBASE_API UGEXPORT
#else
#define CHARTBASE_API UGIMPORT
#endif

#ifdef CHARTTOOLKIT_EXPORTS
#define CHARTTOOLKIT_API UGEXPORT
#else
#define CHARTTOOLKIT_API UGIMPORT
#endif

//  [add by baib begin at 11/23/2011]
#ifdef GEOOPERATION3D_EXPORTS
#define GEOOPERATION3D_API UGEXPORT
#else
#define GEOOPERATION3D_API UGIMPORT
#endif

#ifdef ANALYST3D_EXPORTS
#define ANALYST3D_API UGEXPORT
#else
#define ANALYST3D_API UGIMPORT
#endif
//  [add by baib end at 11/23/2011]


#ifdef MAPTOUCHEDITOR_EXPORTS
#define MAPTOUCHEDITOR_API UGEXPORT
#else
#define MAPTOUCHEDITOR_API UGIMPORT
#endif


#ifdef DATA_EXPORTS
#define DATA_API UGEXPORT
#define DATA_APIC UGEXPORT
#define DATA_APIF 
#else
#define DATA_API UGIMPORT
#define DATA_APIC UGIMPORT
#define DATA_APIF 
#endif

#ifdef MAPPING_EXPORTS
#define MAPPING_API UGEXPORT
#define MAPPING_APIC UGEXPORT
#define MAPPING_APIF 
#else
#define MAPPING_API UGIMPORT
#define MAPPING_APIC UGIMPORT
#define MAPPING_APIF 
#endif

#endif

#define STREAM_APIF
#define TOOLKIT_APIF
#define PROJECTION_APIF
#define GEOMETRY_APIF
#define ENGINE_APIF
#define UDBENGINE_APIF
#define GRAPHICS_APIF
#define GRAPHICSMEM_APIF
#define SYMBOL_APIF
#define SYMBOLMARKER_APIF
#define SYMBOLLINE_APIF
#define SYMBOLFILL_APIF
#define DRAWING_APIF
#define MAP_APIF
#define THEMEBASE_APIF
#define THEMEADVANCE_APIF

#else //ifndef SYMBIAN60
#include "ugexports_symbian.h"
#endif
