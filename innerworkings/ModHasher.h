#include <Cacao.hpp>

typedef struct {
	char name[16];
	uint64_t hooksums;
} ModUUID;

inline ModUUID createModUUID(ModContainer* mc) {
	ModUUID u;
	strncpy(u.name, mc->getName(), 16);

	for (auto& i : mc->getMods()) {
		u.hooksums += (i->getAddress() - getBase());
	}
	return u;
}

struct ModComparer { // why do i need this
   bool operator() (const ModUUID& lhs, const ModUUID& rhs) const
   {
       return lhs.hooksums < rhs.hooksums;
   }
};