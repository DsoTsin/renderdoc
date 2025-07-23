#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
  ptx_resource_type_buffer,
  ptx_resource_type_texture,
  ptx_resource_type_surface,
} ptx_resource_type;

typedef struct fatbin_reflection_container
{
} fatbin_reflection_container;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

uint32_t fatbin_parser_get_version(void);

void *fatbin_load(const uint8_t *data, size_t size);

void fatbin_free(void *fatbin);

size_t fatbin_get_ptx_size(void *fatbin);

const uint8_t *fatbin_get_ptx_data(void *fatbin);

fatbin_reflection_container *fatbin_create_reflection_container(void *fatbin);

void fatbin_free_reflection_container(fatbin_reflection_container *container);

size_t fatbin_reflection_container_get_resource_count(fatbin_reflection_container *container);

void fatbin_reflection_container_iterate_bindings(
    fatbin_reflection_container *container,
    void (*callback)(const int8_t *pname, size_t pnamelen, ptx_resource_type ty, int64_t offset, uint32_t param_index, void*),
    void* userdata);

size_t fatbin_reflection_container_get_param_count(fatbin_reflection_container *container);

void fatbin_reflection_container_iterate_params(
    fatbin_reflection_container *container,
    void (*callback)(const int8_t *pname, size_t pnamelen, int64_t offset, uint32_t param_index,
                     size_t param_size, size_t param_alignment, void *user_data),
    void *user_data);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
