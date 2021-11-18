/**
 * @file
 * @brief This file defines the OP factory
 */
#ifndef R_OP_FACTORY_HPP_
#define R_OP_FACTORY_HPP_

#include "base.hpp"

#include "../factory.hpp"
#include "../util.hpp"


namespace Op {

    /** A factory used to construct Op subclasses
     *  Arguments are passed by non-const forwarding reference
     */
    template <typename T, typename... Args> inline BasePtr factory(Args &&...args) {
        static_assert(Util::Type::Is::ancestor<Base, T>, "T must derive from SOC::Base");
        return ::Factory::factory<Base, T>(std::forward<Args>(args)...);
    }

} // namespace Op

#endif
