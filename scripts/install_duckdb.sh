#!/bin/bash
TEMP_DIR="../temp"

pip install numpy

# check if temp directory exists
if [ ! -d "$TEMP_DIR" ]; then
    echo "$TEMP_DIR doesn't exist. Creating."
fi

# clone the repository
cd $TEMP_DIR
if [ ! -d "duckdb" ]; then
    echo "Cloning DuckDB."
    git clone https://github.com/duckdb/duckdb.git
fi

cd duckdb
git checkout 6ddaae32a751b50a51aa2d0ef8f7d78ed783baf3
if [ ! -d "build/release" ]; then
    export BUILD_PYTHON=1 
    echo "Building DuckDB"
    make
fi

# copy libraries to include and lib paths
cp build/release/src/libduckdb.so $CONDA_PREFIX/lib/
cp src/include/duckdb.h $CONDA_PREFIX/include/
cp src/include/duckdb.hpp $CONDA_PREFIX/include/
cp -R src/include/duckdb $CONDA_PREFIX/include/