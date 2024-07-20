#pragma once

#include "esterv/crypto/arith_uint256.h"
#include <QDataStream>
#include <QString>

namespace esterv::crypto
{

template <unsigned int BITS> class qbase_uint : public base_uint<BITS>
{
    using base_uint<BITS>::base_uint;

  public:
    QString toHex() const;
    void fromHex(const QString &str);
    qbase_uint(const QString str) : base_uint<BITS>()
    {
        this->fromHex(str);
    }

    friend QDataStream &operator>>(QDataStream &in, qbase_uint<BITS> &obj)
    {
        for (auto &v : obj.pn)
            in >> v;
        return in;
    }
    friend QDataStream &operator<<(QDataStream &out, const qbase_uint<BITS> &obj)
    {
        for (const auto &v : obj.pn)
            out << v;
        return out;
    }
};
using uint256 = qbase_uint<256>;
using uint128 = qbase_uint<128>;
}; // namespace esterv::crypto
