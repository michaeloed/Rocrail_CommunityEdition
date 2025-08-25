project(rocint)
# cmake_minimum_required(VERSION 2.8)

add_custom_target(rocint_gen
				  COMMAND ${CMAKE_SOURCE_DIR}/rocs/bin/ogen ${CMAKE_SOURCE_DIR}/rocint/rocint.xml
				  COMMENT "generating c-objects for rocint")
				  
add_custom_target(rocdigs_gen 
				  COMMAND ${CMAKE_SOURCE_DIR}/rocs/bin/ogen 
				  ${CMAKE_SOURCE_DIR}/rocdigs/rocdigs.xml 
				  COMMENT "generating c-objects for rocdigs")
				  
add_custom_target(rocutils_gen
				  COMMAND ${CMAKE_SOURCE_DIR}/rocs/bin/ogen ${CMAKE_SOURCE_DIR}/rocutils/rocutils.xml
				  COMMENT "generating c-objects for rocutils")
				  
add_custom_target(rocs_gen
				  COMMAND ${CMAKE_SOURCE_DIR}/rocs/bin/ogen ${CMAKE_SOURCE_DIR}/rocs/rocs.xml
				  COMMENT "generating c-objects for rocs") 				  
				  
				 				  
				 


