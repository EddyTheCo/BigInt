#include "esterv/crypto/bigint.hpp"
#include <QByteArray>
#include <QIODevice>

namespace esterv::crypto
{
template <unsigned int BITS> QString qbase_uint<BITS>::toHex() const
{

    auto var = QByteArray(BITS / 8, 0);
    QByteArray temp;
    auto buffer = QDataStream(&var, QIODevice::WriteOnly);
    buffer.setByteOrder(QDataStream::LittleEndian);
    buffer << (*this);
    quint8 start = 0;
    std::for_each(var.rbegin(), var.rend(), [&](const auto &v) {
        if (start)
        {
            temp.push_back(v);
        }
        if (v)
        {
            if (!start)
                start = v;
        }
    });
    return QString("0x") + QString::number(start, 16) + temp.toHex();
}
template <unsigned int BITS> void qbase_uint<BITS>::fromHex(const QString &str)
{
    auto var = QByteArray::fromHex(str.toLatin1().remove(0, 2));
    std::reverse(var.begin(), var.end());

    if (var.size() <= BITS / 8)
    {
        var += QByteArray(BITS / 8 - var.size(), 0);
        auto buffer = QDataStream(&var, QIODevice::ReadOnly);
        buffer.setByteOrder(QDataStream::LittleEndian);
        buffer >> (*this);
    }
}
template class qbase_uint<256>;
template class qbase_uint<128>;

}; // namespace qiota
