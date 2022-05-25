#define BOOST_TEST_MODULE tests

#include <boost/test/unit_test.hpp>
#include "Order.h"
#include "OrderExecuted.h"
#include "OrderCancel.h"
#include "OrderShort.h"
#include "OrderTrade.h"

BOOST_AUTO_TEST_CASE(CanceledSharesTest)
{
    OrderCancel orderCancel("S28807197X5K27GA00000P000100");

    BOOST_CHECK_EQUAL(orderCancel.GetCanceledShares(), 100);
}

BOOST_AUTO_TEST_CASE(ExecutedSharesTest)
{
    OrderExecuted orderExecuted("S28807216E5K27GA00000S00010000005AQ00002");

    BOOST_CHECK_EQUAL(orderExecuted.GetExecutedShares(), 100);
}

BOOST_AUTO_TEST_CASE(MinusSharesTestOS)
{
    OrderShort orderShort("S28800011AAK27GA0000DTS000100SH    0000619200Y");
    orderShort.MinusShares(50);

    BOOST_CHECK_EQUAL(orderShort.NumberOfShares(), 50);
}

BOOST_AUTO_TEST_CASE(NumberOfSharesTestOS)
{
    OrderShort orderShort("S28800011AAK27GA0000DTS000100SH    0000619200Y");

    BOOST_CHECK_EQUAL(orderShort.NumberOfShares(), 100);
}

BOOST_AUTO_TEST_CASE(GetStockSymbolTestOS)
{
    OrderShort orderShort("S28800011AAK27GA0000DTS000100SH    0000619200Y");

    BOOST_CHECK_EQUAL(orderShort.GetStockSymbol(), "SH    ");
}

BOOST_AUTO_TEST_CASE(TestOrderID)
{
    Order order("S28807197X5K27GA00000P000100");

    BOOST_CHECK_EQUAL(order.GetOrderID(), "5K27GA00000P");
}

BOOST_AUTO_TEST_CASE(MinusSharesTestTT)
{
    OrderTrade orderTrade("S28803240P4K27GA00003PB000100DXD   0000499600000N4AQ00003");
    orderTrade.MinusShares(50);

    BOOST_CHECK_EQUAL(orderTrade.GetNumberOfShares(), 50);
}

BOOST_AUTO_TEST_CASE(NumberOfSharesTestTT)
{
    OrderTrade orderTrade("S28803240P4K27GA00003PB000100DXD   0000499600000N4AQ00003");

    BOOST_CHECK_EQUAL(orderTrade.GetNumberOfShares(), 100);
}

BOOST_AUTO_TEST_CASE(GetStockSymbolTestTT)
{
    OrderTrade orderTrade("S28803240P4K27GA00003PB000100DXD   0000499600000N4AQ00003");

    BOOST_CHECK_EQUAL(orderTrade.GetStockSymbol(), "DXD   ");
}

