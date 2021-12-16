#ifdef __cplusplus
extern "C" {
#endif

typedef void(*folder_callback)(char const*);
void traverse_directories(char const* searchpaths[], size_t size, folder_callback cb);

#ifdef __cplusplus
}
#endif
