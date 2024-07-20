#include "esterv/crypto/bigint.hpp"

#include <iostream>
#undef NDEBUG
#include <QDebug>
#include <assert.h>

#include <QIODevice>

using namespace esterv::crypto;
int main(int argc, char **argv)
{

    // TEST 1
    uint256 a(3512345678899666655);
    qDebug() << a.toHex();
    assert(a.toHex() == "0x30be5bc927315edf");

    a *= 1234567891;
    qDebug() << a.toHex();
    assert(a.toHex() == "0xe02d83fcda74414de18efcd");

    a += 1234567891098765432;
    qDebug() << a.toHex();
    assert(a.toHex() == "0xe02d83fdec9550996247845");

    uint256 c("0xe02d83fdec9550996247845");
    qDebug() << c.toHex();
    assert(c.toHex() == "0xe02d83fdec9550996247845");

    c -= 1234567891098765432;
    qDebug() << c.toHex();
    assert(c.toHex() == "0xe02d83fcda74414de18efcd");

    c /= 1234567891;
    qDebug() << c.toHex();
    assert(c.toHex() == "0x30be5bc927315edf");

    return 0;
}
