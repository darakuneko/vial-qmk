/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
	k0A, k0B, k0C, k0D, k0E, k0F, k0I, k0J, k0K, k0L, k0M, k0N, k1A, k1B, k1C, k1D, k1E, k1F, k1I, k1J, k1K, k1L, k1M, k1N, k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, k2M, k2N, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K \
) { \
	{k0A, k0B, k0C, k0D, k0E, k0F, XXX, XXX, k0I, k0J, k0K, k0L, k0M, k0N}, \
	{k1A, k1B, k1C, k1D, k1E, k1F, XXX, XXX, k1I, k1J, k1K, k1L, k1M, k1N}, \
	{k2A, k2B, k2C, k2D, k2E, k2F, k2G, k2H, k2I, k2J, k2K, k2L, k2M, k2N}, \
	{XXX, XXX, XXX, k3D, k3E, k3F, k3G, k3H, k3I, k3J, k3K, XXX, XXX, XXX} \
}
