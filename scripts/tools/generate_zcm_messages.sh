#!/bin/bash
#
# Generates the zcm messages
SOFTWARE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" > /dev/null && pwd )"
SOFTWARE_DIR="$(dirname "$SOFTWARE_DIR")"
SOFTWARE_DIR="${SOFTWARE_DIR}/.."
GENERATED_DIR="${SOFTWARE_DIR}/generated/common/messages"
TMP_GENERATED_DIR="/tmp/maav-zcm-files"
ZCM_TYPES_DIR="${SOFTWARE_DIR}/msgtypes/zcm"

echo ${SOFTWARE_DIR}

# Delete Generated messages
if [ -d "${SOFTWARE_DIR}/generated/common" ]; then
    rm -r ${SOFTWARE_DIR}/generated/common
fi

# Delete Temporary stuff
rm -rf ${TMP_GENERATED_DIR}

# Generate hpp files for using with software development
zcm-gen --cpp --cpp-hpath ${GENERATED_DIR} ${ZCM_TYPES_DIR}/*.zcm

# Generate shared library to use with zcm-spy-lite
zcm-gen -c --c-typeinfo --c-hpath ${TMP_GENERATED_DIR} \
	--c-cpath ${TMP_GENERATED_DIR} ${ZCM_TYPES_DIR}/*.zcm
echo "zcm-gen ran successfully"
cd ${TMP_GENERATED_DIR}
cc -c -fPIC ${TMP_GENERATED_DIR}/*.c
echo "object files created successfully"
cc -shared -fPIC -o ${GENERATED_DIR}/zcmlibrary.so *.c
echo "done"
