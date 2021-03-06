/** \file
 * Expression of units in an arbitrary unit system.
 *
 * */

#if ( defined(PHYSICAL_DATA_FOR_RUNTIME) && \
     !defined(runtime_physical_constant_conversion_h) ) || \
    (!defined(PHYSICAL_DATA_FOR_RUNTIME) && \
     !defined(physical_constant_conversion_h) )

#  if defined(PHYSICAL_DATA_FOR_RUNTIME)
#    define runtime_physical_constant_conversion_h
#  else
#    define physical_constant_conversion_h
#  endif


#  include <physical/dimension/define.h>
#  include <physical/dimension/convert.h>
#  include <physical/constant/si.h>



#  if defined (PHYSICAL_DATA_FOR_RUNTIME)
namespace runtime {
#  endif

namespace physical {
  namespace constant {

#include <physical/constant/detail/derived-dimensions.h>

#   define _TQUANTITYn(v,dims)                                  \
    /* definition of where the value is stored. */              \
    template< typename T = system::si >                         \
    struct v {                                                  \
      static const Quantity & value() {                         \
        /* Here is where the generic conversion happens... */   \
        static const Quantity _value                            \
          PHYSICAL_QUANTITY_INITn(                              \
            T::name + "::" + #v,                                \
            ( constant::si::v *                                 \
              make_convert_ratio<T,system::si,dims>::value() ), \
            constant::si::v.name + '(' + T::name + " units)"    \
          );                                                    \
        return _value;                                          \
      }                                                         \
    };

    _TQUANTITYn(pi,                 dimension::unity);
    _TQUANTITYn(c,                  dimension::velocity);
    _TQUANTITYn(Mach,               dimension::velocity);
    _TQUANTITYn(h,                  dimension::angular_momentum);
    _TQUANTITYn(h_bar,              dimension::angular_momentum);
    _TQUANTITYn(g,                  dimension::acceleration);
    _TQUANTITYn(e,                  dimension::charge);
    _TQUANTITYn(eV,                 dimension::energy);
    _TQUANTITYn(keV,                dimension::energy);
    _TQUANTITYn(MeV,                dimension::energy);
    _TQUANTITYn(GeV,                dimension::energy);
    _TQUANTITYn(Rinfinity,          dimension::inverse_length);
    _TQUANTITYn(Rydberg,            dimension::energy);
    _TQUANTITYn(Rydbergs,           dimension::energy);
    _TQUANTITYn(Hartree,            dimension::energy);
    _TQUANTITYn(Hartrees,           dimension::energy);
    _TQUANTITYn(m_e,                dimension::mass);
    _TQUANTITYn(m_p,                dimension::mass);
    _TQUANTITYn(m_d,                dimension::mass);
    _TQUANTITYn(atomic_mass_unit,   dimension::mass);
    _TQUANTITYn(atomic_mass_units,  dimension::mass);
    _TQUANTITYn(amu,                dimension::mass);
    _TQUANTITYn(Dalton,             dimension::mass);
    _TQUANTITYn(Daltons,            dimension::mass);
    _TQUANTITYn(epsilon0,           detail::capacitance_per_length);
    _TQUANTITYn(k_E,                detail::length_per_capacitance);
    _TQUANTITYn(mu0,                dimension::magnetic::permeability);
    _TQUANTITYn(alpha,              dimension::unity);
    _TQUANTITYn(g_e,                dimension::unity);
    _TQUANTITYn(g_d,                dimension::unity);
    _TQUANTITYn(r_e,                dimension::length);
    _TQUANTITYn(lambda_C,           dimension::length);
    _TQUANTITYn(lambda_C_bar,       dimension::length);
    _TQUANTITYn(a_0,                dimension::length);
    _TQUANTITYn(lambda_1eV,         dimension::length);
    _TQUANTITYn(sigma_0,            dimension::area);
    _TQUANTITYn(mu_B,               dimension::magnetic::moment);
    _TQUANTITYn(mu_N,               dimension::magnetic::moment);
    _TQUANTITYn(e_m_e,              dimension::charge_to_mass);
    _TQUANTITYn(e_m_p,              dimension::charge_to_mass);
    _TQUANTITYn(G,                  detail::G_dims);
    _TQUANTITYn(N_A,                dimension::unity);
    _TQUANTITYn(K_B,                detail::K_B_dims);
    _TQUANTITYn(stdtemp,            dimension::temperature);
    _TQUANTITYn(R,                  dimension::unity);
    _TQUANTITYn(V_molar,            dimension::volume);
    _TQUANTITYn(n_0,                dimension::number_density);
    _TQUANTITYn(sigma_SB,           detail::sigma_SB_dims);
    _TQUANTITYn(z0,                 dimension::electric::resistance);
  }/* ****   END UNIT SYSTEM CONSTANTS **** */

#undef _TQUANTITYn
}

#  if defined (PHYSICAL_DATA_FOR_RUNTIME)
}/* namespace runtime. */
#  endif


#endif // physical_constant_conversion_h
