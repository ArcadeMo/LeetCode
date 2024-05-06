#include <iostream>

int main() {
    // 1. Input Assembly
    // Collects raw vertex data from buffers and may also use indices to reuse vertices.

    // 2. Vertex Shader
    // Processes each vertex individually, performing operations like transformations.

    // 3. Tessellation (optional)
    // Subdivides geometry to increase mesh quality and detail.

    // 4. Geometry Shader (optional)
    // Processes entire primitives (points, lines, triangles) and can add or discard vertices.

    // 5. Rasterization
    // Converts primitives into a set of fragments to be shaded. Determines which pixels are covered by the primitive.

    // 6. Fragment Shader
    // Processes each fragment to compute its final color and other attributes.

    // 7. Depth and Stencil Testing
    // Performs depth comparisons and updates the depth buffer, stencil operations can also be performed.

    // 8. Color Blending
    // Combines the fragment's output with the color that is already in the framebuffer.

    // Output the stages to console
    std::cout << "Stages of the graphics pipeline:\n"
              << "1. Input Assembly\n"
              << "2. Vertex Shader\n"
              << "3. Tessellation (Optional)\n"
              << "4. Geometry Shader (Optional)\n"
              << "5. Rasterization\n"
              << "6. Fragment Shader\n"
              << "7. Depth and Stencil Testing\n"
              << "8. Color Blending\n";

    return 0;
}
