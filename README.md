# ngraph-neon

## Installation - New Way

Checkout ngraph++ and python wrapper code and build bdist wheel.

```
git clone --branch python_binding --recursive https://github.com/NervanaSystems/private-ngraph-cpp.git
cd private-ngraph-cpp/python
```
To build python2 bdist wheel type
```
./build2.sh
```
To build python3 bdist wheel type
```
./build3.sh
```

The bdist wheel will be placed in private-ngraph-cpp/python/build/dist
Activate your virtual environment and install the bdist wheel

```
pip install -U <full path to the bdist wheel>
```

For example, On MacOS you would run a command like,

```
pip install -U build/dist/pyngraph-0.0.1-cp27-cp27m-macosx_10_13_intel.whl
```

To run unit tests, first install additional required packages.

```
pip install -r test_requirements.txt
```

Then run a test.
```
pytest test/test_ops.py
```

## Installation - Old Way (Still works)

Follow these steps to install the ngraph's python wrapper and its prerequisites.


### private-ngraph-cpp

Download the required version of private-ngraph-cpp and install it.
```
git clone https://github.com/NervanaSystems/private-ngraph-cpp.git
cd private-ngraph-cpp
git checkout d87b00650360328f14f8906f7371e31b4fe19b5f -b "local branch name"
Build and Install it : https://github.com/NervanaSystems/private-ngraph-cpp#steps
```

### ngraph-neon

After installing private-ngraph-cpp, follow the steps below to install ngraph-neon.
The NGRAPH_CPP_BUILD_PATH is set to default installation location of private-ngraph-cpp.
```
git clone --recursive https://github.com/NervanaSystems/ngraph-neon.git
cd ngraph-neon
export NGRAPH_CPP_BUILD_PATH=$HOME/ngraph_dist/
pip install -U .
```
