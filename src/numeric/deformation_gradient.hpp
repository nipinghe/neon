
#pragma once

#include "numeric/DenseMatrix.hpp"

namespace neon
{
/**
 * Compute the local deformation gradient
 * \f{align*}{ F_{\xi} &= \bf{x}_\xi \f}
 * @param rhea Shape function gradients at quadrature point
 * @param configuration Configuration of the element (coordinates)
 */
template <typename ShapeFunctionDerivatives, typename Configuration>
[[nodiscard]] inline auto local_deformation_gradient(ShapeFunctionDerivatives const& rhea,
                                                     Configuration const& configuration)
{
    return configuration * rhea;
}

/**
 * Compute the deformation gradient, F, from the global to local mapping
 * \f{align*}{
 * F &= F_{\xi} \times (F^0_{\xi})^{-1}
 * \f}
 * @param rhea Shape function derivatives at the integration points
 * @param X Reference configuration (spatial coordinates, local nodes)
 * @param x Current configuration (spatial coordinates, local nodes)
 */
[[nodiscard]] inline Matrix2 deformation_gradient(Matrix const& rhea,
                                                  Matrix2x const& X,
                                                  Matrix2x const& x)
{
    // Deformation gradient in the reference and current configuration
    return local_deformation_gradient(rhea, x) * local_deformation_gradient(rhea, X).inverse();
}

/**
 * Compute the deformation gradient, F, from the global to local mapping
 * \f{align*}{
 * F &= F_{\xi} \times (F^0_{\xi})^{-1}
 * \f}
 * @param rhea Shape function derivatives at the integration points
 * @param X Reference configuration (spatial coordinates, local nodes)
 * @param x Current configuration (spatial coordinates, local nodes)
 */
[[nodiscard]] inline Matrix3 deformation_gradient(Matrix const& rhea,
                                                  Matrix3x const& X,
                                                  Matrix3x const& x)
{
    // Deformation gradient in the reference and current configuration
    return local_deformation_gradient(rhea, x) * local_deformation_gradient(rhea, X).inverse();
}
}
