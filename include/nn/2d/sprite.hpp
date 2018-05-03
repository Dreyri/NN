#pragma once

#include <memory>
#include <vector>

#include "nn/2d/texture.hpp"
#include "nn/2d/vertex.hpp"
#include "nn/stl/rectangle.hpp"

namespace nn {
/**
 * the sprite class represents the information required to draw the sprite on
 * screen. It does not however contain any graphics specific code. That is
 * handled in the sprite renderer
 */
class sprite {
public:
  using vertex_type = vertex2d;
  using index_type = GLushort;

public:
  std::shared_ptr<nn::texture> texture;
  srectangle rect;

  glm::vec2 anchor;

  std::vector<vertex_type> vertices;
  std::vector<index_type> indices;

public:
  sprite(const std::shared_ptr<nn::texture>& tex, const srectangle& rect,
         const glm::ivec2& anchor, const std::vector<vertex_type>& vertices,
         const std::vector<index_type>& indices);
  sprite(const std::shared_ptr<nn::texture>& tex, const srectangle& rect,
         const glm::vec2& anchor);
  sprite(const std::shared_ptr<nn::texture>& tex, const srectangle& rect);
  sprite(const std::shared_ptr<nn::texture>& tex);
};
} // namespace nn