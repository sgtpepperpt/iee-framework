# IEE Framework

The framework exports three utility namespaces (trusted_util, outside_util & tcrypto) that can be used by the external library.

The external library must implement the namespaces defined in the *extern_lib.h* file.

## Namespaces and utility libraries

### Trusted Util

Utility functions (threading, time) inside the enclave.

```namespace trusted_util```

```#include "trusted_util.h"```


### Trusted Crypto

Crypto primitives inside the enclave.

```namespace tcrypto```

```#include "trusted_crypto.h"```


### Outside Util

Wrappers for ocalls, providing an abstraction for common functions, to be used inside the enclave.

```namespace outside_util```

```#include "outside_util.h"```

---

### Untrusted Util

Utility functions (i.e. time) outside the enclave.

```namespace untrusted_util```

```#include "untrusted_util.h"```


### Extern Lib

Functions to be implemented in the external lib.

```namespace extern_lib; namespace extern_lib_ut```

```#include "extern_lib.h"```
