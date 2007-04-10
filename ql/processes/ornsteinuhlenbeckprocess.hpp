/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2003 Ferdinando Ametrano
 Copyright (C) 2001, 2002, 2003 Sadruddin Rejeb
 Copyright (C) 2004, 2005 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file ornsteinuhlenbeckprocess.hpp
    \brief Ornstein-Uhlenbeck process
*/

#ifndef quantlib_ornstein_uhlenbeck_process_hpp
#define quantlib_ornstein_uhlenbeck_process_hpp

#include <ql/stochasticprocess.hpp>

namespace QuantLib {

    //! Ornstein-Uhlenbeck process class
    /*! This class describes the Ornstein-Uhlenbeck process governed by
        \f[
            dx = a (r - x_t) dt + \sigma dW_t.
        \f]

        \ingroup processes
    */
    class OrnsteinUhlenbeckProcess : public StochasticProcess1D {
      public:
        OrnsteinUhlenbeckProcess(Real speed,
                                 Volatility vol,
                                 Real x0 = 0.0,
                                 Real level = 0.0);
        //! \name StochasticProcess interface
        //@{
        Real x0() const;
        Real speed() const;
        Real volatility() const;
        Real level() const;
        Real drift(Time t, Real x) const;
        Real diffusion(Time t, Real x) const;
        Real expectation(Time t0, Real x0, Time dt) const;
        Real stdDeviation(Time t0, Real x0, Time dt) const;
        Real variance(Time t0, Real x0, Time dt) const;
        //@}
      private:
        Real x0_, speed_, level_;
        Volatility volatility_;
    };

}


#endif