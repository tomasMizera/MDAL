/*
 MDAL - Mesh Data Abstraction Library (MIT License)
 Copyright (C) 2019 Peter Petrik (zilolv at gmail dot com)
*/

#ifndef MDAL_UGRID_HPP
#define MDAL_UGRID_HPP

#include <map>
#include <string>
#include <stddef.h>

#include "mdal_cf.hpp"
#include "mdal_driver.hpp"

namespace MDAL
{
  /**
   * Driver of UGRID file format.
   *
   * The result UGRID NetCDF file is strictly based on CF-conventions 1.6
   */
  class DriverUgrid: public DriverCF
  {
    public:
      DriverUgrid();
      ~DriverUgrid() override = default;
      DriverUgrid *create() override;
      void save( const std::string &uri, Mesh *mesh ) override;

    private:
      CFDimensions populateDimensions( ) override;
      void populateElements( Vertices &vertices, Edges &edges, Faces &faces ) override;
      void populateVertices( Vertices &vertices );
      void populateFaces( Faces &faces );
      void populateEdges( Edges &edges );
      void addBedElevation( MemoryMesh *mesh ) override;
      std::string getCoordinateSystemVariableName() override;
      std::set<std::string> ignoreNetCDFVariables() override;
      void parseNetCDFVariableMetadata( int varid, const std::string &variableName,
                                        std::string &name, bool *is_vector, bool *is_x ) override;
      std::string getTimeVariableName() const override;

      void parse2VariablesFromAttribute( const std::string &name, const std::string &attr_name,
                                         std::string &var1, std::string &var2,
                                         bool optional ) const;
      void parseNodeCoordinatesFrom1dMesh( const std::string &meshName,
                                           std::string &var1, std::string &var2 );

      std::vector<std::string> findMeshesNames() const;
      std::vector<std::string> mAllMeshNames; // all mesh names in file
      std::string mMeshName; // processed mesh name
      int mMeshDimension;
      std::string nodeZVariableName() const;

      void populate1DMeshDimensions( MDAL::CFDimensions &dims );
      void populate2DMeshDimensions( MDAL::CFDimensions &dims, int &ncid );

      void writeDimensions( MDAL::Mesh *mesh );
      void writeVariables( MDAL::Mesh *mesh );
      void writeGlobals();
      int faceVerticesMaximumCount() const override
      { return std::numeric_limits<int>::max(); }
  };

} // namespace MDAL

#endif // MDAL_UGRID_HPP
