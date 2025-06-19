# INIT MINIMAL
#
### INSTALL TOOLS AND DEPENDENCIES
```sh
GCC_VERSION=12
LIBC_VERSION=6
sudo apt install --no-install-suggests --no-install-recommends gcc-$GCC_VERSION libc$LIBC_VERSION-dev
```

### COMPILE INIT
```sh
gcc-$GCC_VERSION -static -nostdlib -march=native -mtune=native -Ofast -fno-asynchronous-unwind-tables -fno-ident -fno-pie -ffreestanding -ffunction-sections -fdata-sections -fno-stack-protector -flto -s -o Build/init example_init.c -Wl,--build-id=none,--gc-sections
```

### COMPILE INIT CHROOT
```sh
gcc-$GCC_VERSION -static -nostdlib -march=native -mtune=native -Ofast -fno-asynchronous-unwind-tables -fno-ident -fno-pie -ffreestanding -ffunction-sections -fdata-sections -fno-stack-protector -flto -s -o Build/init_chroot example_init_chroot.c -Wl,--build-id=none,--gc-sections
```