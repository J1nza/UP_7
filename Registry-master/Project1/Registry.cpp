#include "Registry.hpp"

namespace Falokut
{
	namespace Registry
	{
		RegistryKey_ptr ClassesRoot(new RegistryKey(HKEY_CLASSES_ROOT));
		RegistryKey_ptr CurrentUser(new RegistryKey(HKEY_CURRENT_USER));
		RegistryKey_ptr LocalMachine(new RegistryKey(HKEY_LOCAL_MACHINE));
		RegistryKey_ptr Users(new RegistryKey(HKEY_USERS));
		RegistryKey_ptr CurrentConfig(new RegistryKey(HKEY_CURRENT_CONFIG));
	}
}
