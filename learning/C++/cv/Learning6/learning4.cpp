#include <array>
#include <memory>
template <class T, int SIZE>
struct Image {
    using Ptr = std::unique_ptr<Image<T, SIZE>>;
    std::array<T, SIZE> data{};
};
template <int SIZE>
using Imagef = Image<float, SIZE>;
int main() {
    using Image3f = Imagef<3>;
    auto image_ptr = std::make_unique<Image3f>();
    image_ptr->data[0] = 1.0f;
    image_ptr->data[1] = 2.0f;
    image_ptr->data[2] = 3.0f;
    return 0;
}