#pragma once

#include <memory>

#include <glm/glm.hpp>

#include "nn/render/mesh.hpp"
#include "nn/render/texture.hpp"
#include "nn/render/vertex.hpp"

namespace nn {
class renderable2d {
public:
  using vertex_type = vertex2d;
  using index_type = GLushort;
  using mesh_type = nn::mesh<vertex_type, index_type>;

public:
  mesh_type mesh;
  std::shared_ptr<nn::texture> texture;

public:
  renderable2d(const mesh_type& mesh, const std::shared_ptr<nn::texture>& tex);
  renderable2d(renderable2d&&) noexcept = default;
  virtual ~renderable2d();

  virtual glm::vec2 origin() const;
};
} // namespace nn