// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: Apache-2.0

#ifndef PALACE_LIBCEED_HCURL_H1D_BUILD_QF_H
#define PALACE_LIBCEED_HCURL_H1D_BUILD_QF_H

#include "coeff_qf.h"
#include "utils_qf.h"

// Build functions replace active vector output with quadrature point data and remove active
// vector input.

CEED_QFUNCTION(f_build_hcurlh1d_22)(void *__restrict__ ctx, CeedInt Q,
                                    const CeedScalar *const *in, CeedScalar *const *out)
{
  const CeedScalar *attr = in[0], *wdetJ = in[0] + Q, *adjJt = in[0] + 2 * Q;
  CeedScalar *qd = out[0];

  CeedPragmaSIMD for (CeedInt i = 0; i < Q; i++)
  {
    CeedScalar coeff[3], adjJt_loc[4], qd_loc[4];
    CoeffUnpack2((const CeedIntScalar *)ctx, (CeedInt)attr[i], coeff);
    MatUnpack22(adjJt + i, Q, adjJt_loc);
    MultBA22(adjJt_loc, coeff, qd_loc);

    qd[i + Q * 0] = wdetJ[i] * qd_loc[0];
    qd[i + Q * 1] = wdetJ[i] * qd_loc[1];
    qd[i + Q * 2] = wdetJ[i] * qd_loc[2];
    qd[i + Q * 3] = wdetJ[i] * qd_loc[3];
  }
  return 0;
}

CEED_QFUNCTION(f_build_hcurlh1d_33)(void *__restrict__ ctx, CeedInt Q,
                                    const CeedScalar *const *in, CeedScalar *const *out)
{
  const CeedScalar *attr = in[0], *wdetJ = in[0] + Q, *adjJt = in[0] + 2 * Q;
  CeedScalar *qd = out[0];

  CeedPragmaSIMD for (CeedInt i = 0; i < Q; i++)
  {
    CeedScalar coeff[6], adjJt_loc[9], qd_loc[9];
    CoeffUnpack3((const CeedIntScalar *)ctx, (CeedInt)attr[i], coeff);
    MatUnpack33(adjJt + i, Q, adjJt_loc);
    MultBA33(adjJt_loc, coeff, qd_loc);

    qd[i + Q * 0] = wdetJ[i] * qd_loc[0];
    qd[i + Q * 1] = wdetJ[i] * qd_loc[1];
    qd[i + Q * 2] = wdetJ[i] * qd_loc[2];
    qd[i + Q * 3] = wdetJ[i] * qd_loc[3];
    qd[i + Q * 4] = wdetJ[i] * qd_loc[4];
    qd[i + Q * 5] = wdetJ[i] * qd_loc[5];
    qd[i + Q * 6] = wdetJ[i] * qd_loc[6];
    qd[i + Q * 7] = wdetJ[i] * qd_loc[7];
    qd[i + Q * 8] = wdetJ[i] * qd_loc[8];
  }
  return 0;
}

CEED_QFUNCTION(f_build_hcurlh1d_21)(void *__restrict__ ctx, CeedInt Q,
                                    const CeedScalar *const *in, CeedScalar *const *out)
{
  const CeedScalar *attr = in[0], *wdetJ = in[0] + Q, *adjJt = in[0] + 2 * Q;
  CeedScalar *qd = out[0];

  CeedPragmaSIMD for (CeedInt i = 0; i < Q; i++)
  {
    CeedScalar coeff[3], adjJt_loc[2], qd_loc[1];
    CoeffUnpack2((const CeedIntScalar *)ctx, (CeedInt)attr[i], coeff);
    MatUnpack21(adjJt + i, Q, adjJt_loc);
    MultBA21(adjJt_loc, coeff, qd_loc);

    qd[i + Q * 0] = wdetJ[i] * qd_loc[0];
  }
  return 0;
}

CEED_QFUNCTION(f_build_hcurlh1d_32)(void *__restrict__ ctx, CeedInt Q,
                                    const CeedScalar *const *in, CeedScalar *const *out)
{
  const CeedScalar *attr = in[0], *wdetJ = in[0] + Q, *adjJt = in[0] + 2 * Q;
  CeedScalar *qd = out[0];

  CeedPragmaSIMD for (CeedInt i = 0; i < Q; i++)
  {
    CeedScalar coeff[6], adjJt_loc[6], qd_loc[4];
    CoeffUnpack3((const CeedIntScalar *)ctx, (CeedInt)attr[i], coeff);
    MatUnpack32(adjJt + i, Q, adjJt_loc);
    MultBA32(adjJt_loc, coeff, qd_loc);

    qd[i + Q * 0] = wdetJ[i] * qd_loc[0];
    qd[i + Q * 1] = wdetJ[i] * qd_loc[1];
    qd[i + Q * 2] = wdetJ[i] * qd_loc[2];
    qd[i + Q * 3] = wdetJ[i] * qd_loc[3];
  }
  return 0;
}

#endif  // PALACE_LIBCEED_HCURL_H1D_BUILD_QF_H