/*
 * Copyright (C) 2010-2022 The ESPResSo project
 * Copyright (C) 2002,2003,2004,2005,2006,2007,2008,2009,2010
 */

#ifndef SCRIPT_INTERFACE_SHAPES_CHANNEL_HPP
#define SCRIPT_INTERFACE_SHAPES_CHANNEL_HPP

#include "script_interface/shapes/Shape.hpp"

#include <shapes/Channel.hpp>

#include <memory>

namespace ScriptInterface {
namespace Shapes {

class Channel : public Shape {
public:
  Channel() : m_channel(std::make_shared<::Shapes::Channel>()) {
    add_parameters({{"width",
                     [this](Variant const &v) { m_channel->set_dimensions(get_value<double>(v), m_channel->depth()); },
                     [this]() { return m_channel->width(); }},
                    {"depth",
                     [this](Variant const &v) { m_channel->set_dimensions(m_channel->width(), get_value<double>(v)); },
                     [this]() { return m_channel->depth(); }}});
  }

  std::shared_ptr<::Shapes::Shape> shape() const override { return m_channel; }

private:
  std::shared_ptr<::Shapes::Channel> m_channel;
};

} /* namespace Shapes */
} /* namespace ScriptInterface */

#endif /* SCRIPT_INTERFACE_SHAPES_CHANNEL_HPP */
