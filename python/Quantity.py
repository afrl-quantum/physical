from exceptions import RuntimeError

class Quantity:
    """
    This is the documentation for a physical Quantity.
    """

    def __init__(self,coeff,units):
        self.coeff = 1. * coeff
        self.units = units.copy()
        for k in self.units.keys():
            if self.units[k] == 0:
                del self.units[k]

    def __repr__(self):
        # first sort into pos or neg exponent (of units)
        utuples = self.units.items()
        # insert marker tuple
        marker = ('--',0)
        utuples.append(marker)
        utuples.sort(lambda (k1,v1),(k2,v2): cmp(v2,0))

        # find marker
        mi = utuples.index(marker)

        # separate into separate tuples and then sort lexically
        putuples = utuples[:mi]
        nutuples = utuples[(mi+1):]
        putuples.sort(lambda (k1,v1),(k2,v2): cmp(k1,k2))
        nutuples.sort(lambda (k1,v1),(k2,v2): cmp(k1,k2))

        str = '<%g' % self.coeff

        # numerator first
        for u,e in putuples:
            str = str + ' ' + u
            if e != 1:
                str = str + '^' + `e`

        # now denominator
        if nutuples != []:
            str = str + ' /'

        for u,e in nutuples:
            str = str + ' ' + u
            if e != -1:
                str = str + '^' + `-e`

        return str + '>'

    def __add__(self,other):
        self.unitsMatch(other)
        return Quantity(self.coeff + other.coeff, self.units)

    def __sub__(self,other):
        self.unitsMatch(other)
        return Quantity(self.coeff - other.coeff, self.units)

    def __cmp__(self,other):
        self.unitsMatch(other)
        return cmp(self.coeff, other.coeff)

    def __mul__(self,other):
        if other.__class__ == Quantity:
            c = 1. * self.coeff * other.coeff
            u = self.multUnits(other, 1)
            if u.keys() == [ ]:
                return c
            return Quantity(c, u)
        else:
            # implicitly call either other.__mul__ or self.__rmul__
            # other.__mul__ should be automatically called for more complex
            # types, such as numpy.ndarray.  For basic types (int,float,...),
            # self.__rmul__ should be called. 
            return other * self

    def __rmul__(self,other):
        # we are assuming that if __rmul__ was called, other must be a
        # fundamental numeric type.  Otherwise, other.__mul__ should have been
        # called (which might in turn call Quantity.__rmul__).  This works for
        # instance if we do (Quantity)*(numpy.ndarray).
        return Quantity(other * self.coeff, self.units)

    # assume that the type in coeff supports truediv
    def __truediv__(self,other):
        return self.__div__(other)

    # assume that the type in coeff supports truediv
    def __rtruediv__(self,other):
        return self.__rdiv__(other)

    def __div__(self,other):
        try:
            c = 1. * self.coeff / other.coeff
            u = self.multUnits(other, -1)
        except AttributeError:
            c = 1. * self.coeff / other
            u = self.units
        if u.keys() == [ ]:
            return c
        else:
            return Quantity(c, u)

    def __rdiv__(self,other):
        c = other / self.coeff
        u = self.units.copy()
        for k in u.keys():
            u[k] = -u[k]
        return Quantity(c, u)

    def __pow__(self,exponent):
        # now loop through each of the units and try to divide/multiply the
        # power by the 'exponent'.  Throw an exception of this is not
        # possible. 
        u = self.units.copy()
        for k in u.keys():
            if abs(exponent) < 1:
                if ((float(u[k]) % (1.0/float(abs(exponent)))) != 0):
                    raise RuntimeError(UnitsNotRoot)
            elif (abs(exponent)% 1) != 0:
                raise RuntimeError(UnitsNotDimensionless)
            u[k] = int(u[k] * exponent)

        c  = self.coeff ** exponent
        return Quantity(c, u)

    def __neg__(self):
        return Quantity(-self.coeff, self.units)

    def __abs__(self):
        return Quantity(abs(self.coeff), self.units)

    def __complex__(self):
        return complex(self.coeff)

    def __float__(self):
        return float(self.coeff)

    def __int__(self):
        return int(self.coeff)

    def __long__(self):
        return long(self.coeff)

    def multUnits(self,other,n):
        u = self.units.copy()
        for k in u.keys():
            if k in other.units.keys():
                u[k] = u[k] + n * other.units[k]
        for k in other.units.keys():
            if k not in u.keys():
                u[k] = n * other.units[k]
        for k in u.keys():
            if u[k] == 0:
                del u[k]
        return u

    def unitsMatch(self,other):
        if other.__class__ != Quantity:
            raise RuntimeError(UnitsMismatch)

        otherkeys = other.units.keys()
        for k in self.units.keys():
            if k not in otherkeys:
                raise RuntimeError(UnitsMismatch)
            if self.units[k] != other.units[k]:
                raise RuntimeError(UnitsMismatch)

UnitsMismatch = 'Units mismatch:  cannot add/subtract/compare mismatched units'
UnitsNotRoot  = 'Units not root:  cannot take non-even root of units'
UnitsNotDimensionless = 'Units not dimensionless:  cannot create non-even powers of unit'
