* $Id$
C
C
	FUNCTION SUBCRS6(T,U)
	IMPLICIT REAL*8(A-H,O-Z)
	SUBCRS6=(1.D0+U**2)*(1.D0/T**2-4.D0/U/9.D0)
	RETURN
	END
