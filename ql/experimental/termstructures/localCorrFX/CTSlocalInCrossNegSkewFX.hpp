/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C)  2017 Cord Harms

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file localcorrsurface.hpp
    \brief Local NegSkew surface derived ....
*/

#ifndef quantlib_localInCrossNegSkew_hpp
#define quantlib_localInCrossNegSkew_hpp

#include <ql/experimental/termstructures/localCorrFX/localcorrsurfaceabfFX.hpp>

namespace QuantLib {

    //! Local NegSkew surface derived 
    /*! For details about this implementation refer to
        
        \bug this class is untested, probably unreliable.
    */
    class CTSlocalInCrossNegSkewFX : public LocalCorrSurfaceABFFX {
      public:
		  CTSlocalInCrossNegSkewFX(const std::vector<boost::shared_ptr<QuantLib::GeneralizedBlackScholesProcess>>& processes,
								  const boost::shared_ptr<QuantLib::GeneralizedBlackScholesProcess>&					processToCal,
									double beta);
		  CTSlocalInCrossNegSkewFX(const std::vector<boost::shared_ptr<QuantLib::HestonSLVProcess>>& processes,
			  const boost::shared_ptr<QuantLib::GeneralizedBlackScholesProcess>&					processToCal,
			  double beta,
			  const RealStochasticProcess::MatA											    correlation);

		  //@}
		  //! \name Visitability
		  //@{
		  virtual void accept(AcyclicVisitor&);
        //@}
		  virtual QuantLib::Real localA(Time t, const RealStochasticProcess::VecA& assets,
			  bool extrapolate = false) const;
		  virtual QuantLib::Real localB(Time t, const RealStochasticProcess::VecA& assets,
			  bool extrapolate = false) const;
      protected:
		  //virtual void initializeF();
	  private:
		  double beta_;
    };

}

#endif
