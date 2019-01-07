#ifndef GRAPHICS_PRIVATE_H
#define GRAPHICS_PRIVATE_H

#ifndef M3D_BUILD
#error This file is for m3diaLib-internal use only!
#endif

#pragma once
#include <3ds.h>
#include <vector>
#include "m3d/graphics/renderContext.hpp"

namespace m3d {
    class Camera;
    class Material;
    class Mesh;
    class RenderTarget;
    class Screen;
    class Texture;
    struct Vertex;

    namespace priv {
        namespace graphics {
            extern m3d::Camera defaultCamera0, defaultCamera1;
            extern int maxFaces;

            class GPU {
            friend class m3d::Screen;
            friend class m3d::Mesh;
            public:
                static void renderTo(const m3d::RenderTarget& t_target);
                static void useMode(m3d::RenderContext::Mode t_mode);
                static void addVertex(Vertex t_vertex);
                static void bindTexture(int t_texEnv, const m3d::Texture& t_texture);
                static void setMaterial(const m3d::Material& t_material);
                static void draw();

            private:
                /* data */
                static int m_vertexAmount, m_lastPos;
                static Vertex* m_vertexBuffer;
                static m3d::RenderContext::Mode m_mode;
            };
        } /* graphics */
    } /* priv */
} /* m3d */


#endif /* end of include guard: GRAPHICS_PRIVATE_H */
