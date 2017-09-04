
#pragma once

namespace neon
{
class InternalVariables;
class Material;

/**
 * ConstitutiveModel is the base class for all constitutive models.  The derived
 * classes define their own internal variables, implement an update internal
 * variables routine and update a constitutive model for use in the global
 * assembly routine
 */
class ConstitutiveModel
{
public:
    /** Provide an internal variable class to be populated by the constitutive model */
    ConstitutiveModel(InternalVariables& variables) : variables(variables) {}

    /**
     * Update the required internal variables and tangent matrix at quadrature
     * points
     * @param time_step_size Time step size (or load increment if quasi-static)
     */
    virtual void update_internal_variables(double const time_step_size) = 0;

    /** @return A base class reference to the common material properties */
    virtual Material const& intrinsic_material() const = 0;

    virtual bool is_finite_deformation() const = 0;

    virtual bool is_symmetric() const { return true; };

protected:
    InternalVariables& variables;
};
}
