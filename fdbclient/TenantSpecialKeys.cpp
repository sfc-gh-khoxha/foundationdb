/*
 * TenantSpecialKeys.cpp
 *
 * This source file is part of the FoundationDB open source project
 *
 * Copyright 2013-2022 Apple Inc. and the FoundationDB project authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "fdbclient/TenantSpecialKeys.actor.h"

template <>
const KeyRangeRef TenantRangeImpl<true>::submoduleRange = KeyRangeRef("tenant/"_sr, "tenant0"_sr);

template <>
const KeyRangeRef TenantRangeImpl<true>::mapSubRange = KeyRangeRef("map/"_sr, "map0"_sr);

template <>
const KeyRangeRef TenantRangeImpl<true>::renameSubRange = KeyRangeRef("rename/"_sr, "rename0"_sr);

template <>
const KeyRangeRef TenantRangeImpl<false>::submoduleRange = KeyRangeRef(""_sr, "\xff"_sr);

template <>
const KeyRangeRef TenantRangeImpl<false>::mapSubRange = KeyRangeRef("tenant_map/"_sr, "tenant_map0"_sr);

template <>
const KeyRangeRef TenantRangeImpl<false>::renameSubRange = KeyRangeRef("tenant_rename/"_sr, "tenant_rename0"_sr);

template <>
bool TenantRangeImpl<true>::subRangeIntersects(KeyRangeRef subRange, KeyRangeRef range) {
	return subRange.intersects(range);
}

template <>
bool TenantRangeImpl<false>::subRangeIntersects(KeyRangeRef subRange, KeyRangeRef range) {
	return subRange == mapSubRange;
}