#include <sstream>
#include <map>
#include <vector>

#include <init.h>
#include <messageSender.h>


namespace math
{

struct vector
{
    float x, y, z;
};

} // namespace math

namespace engine
{
namespace graphics
{
struct Shape
{
    // ...
};
} // namespace graphics
} // namespace engine

// using namespace std;
// using namespace math;

int main()
{
	init();

	messageSender::send("Running 04-Namespaces project");

    std::map<int, int> map;
    std::vector<int> numbersList = {1, 2, 3};
    math::vector direction = {1, 2, 3};

    using std::vector;
    vector<int> anotherNumbersList = {1, 2, 3};

    return 0;
}
