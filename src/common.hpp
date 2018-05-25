/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2018,  Regents of the University of California
 *
 * This file is part of NAC (Name-based Access Control for NDN).
 * See AUTHORS.md for complete list of NAC authors and contributors.
 *
 * NAC is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NAC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NAC, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @author Zhiyi Zhang <zhiyi@cs.ucla.edu>
 */

#ifndef NAC_COMMON_HPP
#define NAC_COMMON_HPP

#include "config.hpp"

#ifdef NDN_GEP_HAVE_TESTS
#define VIRTUAL_WITH_TESTS virtual
#define PUBLIC_WITH_TESTS_ELSE_PROTECTED public
#define PUBLIC_WITH_TESTS_ELSE_PRIVATE public
#define PROTECTED_WITH_TESTS_ELSE_PRIVATE protected
#else
#define VIRTUAL_WITH_TESTS
#define PUBLIC_WITH_TESTS_ELSE_PROTECTED protected
#define PUBLIC_WITH_TESTS_ELSE_PRIVATE private
#define PROTECTED_WITH_TESTS_ELSE_PRIVATE private
#endif

/** \def DECL_OVERRIDE
 *  \brief expands to 'override' if compiler supports this feature, otherwise expands to nothing
 */
#ifdef HAVE_CXX_OVERRIDE
#define DECL_OVERRIDE override
#else
#define DECL_OVERRIDE
#endif

#include <cstddef>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <ndn-cxx/common.hpp>
#include <ndn-cxx/data.hpp>
#include <ndn-cxx/interest.hpp>
#include <ndn-cxx/util/signal.hpp>
#include <ndn-cxx/link.hpp>

#include <ndn-cxx/security/v2/key-chain.hpp>
#include <ndn-cxx/security/v2/validation-callback.hpp>
#include <ndn-cxx/security/v2/validation-error.hpp>
#include <ndn-cxx/security/v2/validator.hpp>
#include <ndn-cxx/security/validator-null.hpp>

#include <boost/algorithm/string.hpp>
#include <boost/asio.hpp>
#include <boost/assert.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/noncopyable.hpp>
#include <boost/property_tree/ptree.hpp>

namespace ndn {
namespace nac {

using std::size_t;

using boost::noncopyable;

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;
using std::bad_weak_ptr;
using std::make_shared;
using std::enable_shared_from_this;

using std::static_pointer_cast;
using std::dynamic_pointer_cast;
using std::const_pointer_cast;

using std::function;
using std::bind;
using std::ref;
using std::cref;

using ndn::Interest;
using ndn::Data;
using ndn::Name;
using ndn::Exclude;
using ndn::Block;

using security::v2::Certificate;
using ndn::security::v2::Validator;
using ndn::security::ValidatorNull;
using security::v2::DataValidationSuccessCallback;
using security::v2::DataValidationFailureCallback;
using security::v2::ValidationError;

namespace tlv {
using namespace ndn::tlv;
} // namespace tlv

namespace name = ndn::name;
namespace time = ndn::time;
namespace signal = ndn::util::signal;

const ndn::name::Component NAME_COMPONENT_BY("BY");
const ndn::name::Component NAME_COMPONENT_E_KEY("E-KEY");
const ndn::name::Component NAME_COMPONENT_D_KEY("D-KEY");
const ndn::name::Component NAME_COMPONENT_C_KEY("C-KEY");

} // namespace nac
} // namespace ndn

#endif // NAC_COMMON_HPP