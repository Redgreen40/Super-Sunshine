#ifndef GEOMETRIC_SHAPE_H
#define GEOMETRIC_SHAPE_H

#include "Point.h"
#include "Normal.h"
#include "Material.h"
#include "Intersection.h"
#include "TextureDescription.h"

/*
Description:

   The GeometricShape class is the base from which the Triangle and Sphere classes inherit.

   It specifies three pure virtual functions which must be implemented by the classes that inherit from it.
   These functions are common to all geometric shapes, but implemented differently for each type of geometric shape.

   It also provides three common member variables:

   - The ambient illumination.
   - The material.
   - The texture.
*/

class Ray;

class GeometricShape
{
public:

   GeometricShape(const Colour& ambient, Material* material);
   GeometricShape(TextureDescription* textureDescription, Material* material);
   virtual ~GeometricShape();

   virtual bool isIntersected(const Ray& ray, Intersection* intersection) const = 0;
   virtual bool isIntersected(const Ray& ray, float& distAlongRayToIntersection) const = 0;
   virtual bool isIntersected(const Ray& ray) const = 0;

   Colour getAmbient() const;
   Colour getAmbient(const Point& barycentricCoord) const;

   Material * getMaterial() const;

   bool isTextured() const;

private:

   Colour ambient;
   Material* material;

   bool textured;
   TextureDescription* textureDescription;
};

#endif

