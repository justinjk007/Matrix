// Hossein Moein
// February 11, 2018
// Copyright (C) 2018-2019 Hossein Moein
// Distributed under the BSD Software License (see file License)

#include <MatrixBase.h>

// ----------------------------------------------------------------------------

//
// Dense Matrix Storage
//

// ----------------------------------------------------------------------------

namespace hmma
{

template<class T, class S>
void DenseMatrixStorage<T, S>::
_resize (size_type in_row,
         size_type in_col,
         size_type data_size,
         bool set_all_to_def,
         const_reference def_value)  {

    if (data_size != data_.size ())
        data_.resize (data_size, def_value);
    if (set_all_to_def)
        std::fill (data_.begin (), data_.end (), def_value);

    rows_ = in_row;
    cols_ = in_col;
    return;
}

// ----------------------------------------------------------------------------

template<class T, class S>
void DenseMatrixStorage<T, S>::clear () noexcept  {

    data_.clear ();
    rows_ = 0;
    cols_ = 0;
    return;
}

// ----------------------------------------------------------------------------

template<class T, class S>
inline void DenseMatrixStorage<T, S>::
swap (DenseMatrixStorage &rhs) noexcept  {

    data_.swap (rhs.data_);
    std::swap (rows_, rhs.rows_);
    std::swap (cols_, rhs.cols_);

    return;
}

} // namespace hmma

// ----------------------------------------------------------------------------

// Local Variables:
// mode:C++
// tab-width:4
// c-basic-offset:4
// End:
