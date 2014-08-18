/*
 * Qt4 bitcoin GUI.
 *
 * W.J. van der Laan 2011-2012
 * The Bitcoin Developers 2011-2013
 */
#include "walletframe.h"
#include "bitcoingui.h"
#include "walletstack.h"
#include "walletview.h"

#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>

WalletFrame::WalletFrame(BitcoinGUI *_gui) :
    QFrame(_gui),
    gui(_gui),
    clientModel(0)
{

     // create the top bar with coin amounts
     frame_coinamount = new QFrame(this);
     frame_coinamount->setObjectName(QString::fromUtf8("frame_coinamount"));
     frame_coinamount->setGeometry(QRect(0, 0, 905, 40));
     QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
     sizePolicy.setHorizontalStretch(0);
     sizePolicy.setVerticalStretch(0);
     sizePolicy.setHeightForWidth(frame_coinamount->sizePolicy().hasHeightForWidth());
     frame_coinamount->setSizePolicy(sizePolicy);
     frame_coinamount->setMinimumSize(QSize(0, 40));
     frame_coinamount->setMaximumHeight(40);
     frame_coinamount->setFrameShape(QFrame::NoFrame);
     frame_coinamount->setFrameShadow(QFrame::Raised);
     frame_coinamount->setLineWidth(0);
     gridLayout = new QGridLayout(frame_coinamount);
     gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
     gridLayout->setContentsMargins(-1, 0, -1, -1);
     labelImmatureText = new QLabel(frame_coinamount);
     labelImmatureText->setObjectName(QString::fromUtf8("labelImmatureText"));

     gridLayout->addWidget(labelImmatureText, 0, 8, 1, 1);

     labelUnconfirmed = new QLabel(frame_coinamount);
     labelUnconfirmed->setObjectName(QString::fromUtf8("labelUnconfirmed"));
     labelUnconfirmed->setMinimumSize(QSize(140, 0));
     QFont font;
     font.setBold(true);
     font.setWeight(75);
     labelUnconfirmed->setFont(font);
     labelUnconfirmed->setContentsMargins(0, 10, 0, 0);
     labelUnconfirmed->setCursor(QCursor(Qt::IBeamCursor));
     labelUnconfirmed->setText(QString::fromUtf8("0 NLG"));
     labelUnconfirmed->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
     labelUnconfirmed->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

     gridLayout->addWidget(labelUnconfirmed, 0, 6, 1, 1);

     labelImmature = new QLabel(frame_coinamount);
     labelImmature->setObjectName(QString::fromUtf8("labelImmature"));
     labelImmature->setMinimumSize(QSize(140, 0));
     labelImmature->setFont(font);
     labelImmature->setContentsMargins(0, 10, 0, 0);
     labelImmature->setText(QString::fromUtf8("0 NLG"));
     labelImmature->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
     labelImmature->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

     gridLayout->addWidget(labelImmature, 0, 10, 1, 1);

     lblIcon = new QLabel(frame_coinamount);
     lblIcon->setObjectName(QString::fromUtf8("lblIcon"));
     QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
     sizePolicy1.setHorizontalStretch(0);
     sizePolicy1.setVerticalStretch(0);
     sizePolicy1.setHeightForWidth(lblIcon->sizePolicy().hasHeightForWidth());
     lblIcon->setSizePolicy(sizePolicy1);
     lblIcon->setMinimumSize(QSize(40, 40));
     lblIcon->setMaximumSize(QSize(40, 40));
     lblIcon->setBaseSize(QSize(40, 40));
     lblIcon->setPixmap(QPixmap(QString::fromUtf8(":/icons/balanceicon")));
     lblIcon->setScaledContents(true);

     gridLayout->addWidget(lblIcon, 0, 0, 1, 1);

     labelBalance = new QLabel(frame_coinamount);
     labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
     labelBalance->setFont(font);
     labelBalance->setContentsMargins(0, 10, 0, 0);
     labelBalance->setCursor(QCursor(Qt::IBeamCursor));
     labelBalance->setLayoutDirection(Qt::LeftToRight);
     labelBalance->setText(QString::fromUtf8("0 NLG"));
     labelBalance->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
     labelBalance->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

     gridLayout->addWidget(labelBalance, 0, 3, 1, 1);

     horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

     horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

     gridLayout->addItem(horizontalSpacer_4, 0, 7, 1, 1);

     label_6 = new QLabel(frame_coinamount);
     label_6->setObjectName(QString::fromUtf8("label_6"));

     gridLayout->addWidget(label_6, 0, 2, 1, 1);

     label_7 = new QLabel(frame_coinamount);
     label_7->setObjectName(QString::fromUtf8("label_7"));

     gridLayout->addWidget(label_7, 0, 5, 1, 1);

     horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

     gridLayout->addItem(horizontalSpacer_5, 0, 1, 1, 1);

     labelImmatureText->setText(tr("Immature:"));
#ifndef QT_NO_TOOLTIP
     labelUnconfirmed->setToolTip(tr("Total of transactions that have yet to be confirmed, and do not yet count toward the current balance"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
     labelImmature->setToolTip(tr("Mined balance that has not yet matured"));
#endif // QT_NO_TOOLTIP
     lblIcon->setText(QString());
#ifndef QT_NO_TOOLTIP
     labelBalance->setToolTip(tr("Your current balance"));
#endif // QT_NO_TOOLTIP
     label_6->setText(tr("Balance:"));
     label_6->setContentsMargins(0, 10, 0, 0);
     label_7->setText(tr("Unconfirmed:"));
	 label_7->setContentsMargins(0, 10, 0, 0);


     // Create VBox hook for adding widgets
    QVBoxLayout *walletFrameLayout = new QVBoxLayout(this);
    setContentsMargins(0,0,0,0);
    walletStack = new WalletStack(this);
    walletStack->setBitcoinGUI(gui);
    walletFrameLayout->setContentsMargins(0,0,0,0);
    walletFrameLayout->addWidget(frame_coinamount);
    walletFrameLayout->addWidget(walletStack);

    QLabel *noWallet = new QLabel(tr("No wallet has been loaded."));
    noWallet->setAlignment(Qt::AlignCenter);
    walletStack->addWidget(noWallet);
}

WalletFrame::~WalletFrame()
{
}

void WalletFrame::setClientModel(ClientModel *clientModel)
{
    this->clientModel = clientModel;
    walletStack->setClientModel(clientModel);
}

bool WalletFrame::addWallet(const QString& name, WalletModel *walletModel)
{
    return walletStack->addWallet(name, walletModel);
}

bool WalletFrame::setCurrentWallet(const QString& name)
{
    // TODO: Check if valid name
    walletStack->setCurrentWallet(name);
    return true;
}

void WalletFrame::removeAllWallets()
{
    walletStack->removeAllWallets();
}

bool WalletFrame::handleURI(const QString &uri)
{
    WalletView *walletView = currentWalletView();
    if (!walletView)
        return false;

    return walletStack->handleURI(uri);
}

void WalletFrame::showOutOfSyncWarning(bool fShow)
{
    if (!walletStack) {
        QMessageBox box;
        box.setText("walletStack is null");
        box.exec();
        return;
    }
    walletStack->showOutOfSyncWarning(fShow);
}

void WalletFrame::gotoOverviewPage()
{
    walletStack->gotoOverviewPage();
}

void WalletFrame::gotoHistoryPage()
{
    walletStack->gotoHistoryPage();
}

void WalletFrame::gotoAddressBookPage()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletStack->gotoAddressBookPage();
}

void WalletFrame::gotoReceiveCoinsPage()
{
    walletStack->gotoReceiveCoinsPage();
}

void WalletFrame::gotoSendCoinsPage(QString addr)
{
    walletStack->gotoSendCoinsPage(addr);
}

void WalletFrame::gotoSignMessageTab(QString addr)
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoSignMessageTab(addr);
}

void WalletFrame::gotoVerifyMessageTab(QString addr)
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->gotoVerifyMessageTab(addr);
}

void WalletFrame::encryptWallet(bool status)
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->encryptWallet(status);
}

void WalletFrame::backupWallet()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->backupWallet();
}

void WalletFrame::changePassphrase()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->changePassphrase();
}

void WalletFrame::unlockWallet()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletView->unlockWallet();
}

void WalletFrame::setEncryptionStatus()
{
    WalletView *walletView = currentWalletView();
    if (walletView)
        walletStack->setEncryptionStatus();
}

WalletView *WalletFrame::currentWalletView()
{
    return qobject_cast<WalletView*>(walletStack->currentWidget());
}

void WalletFrame::setBalance(QString balance, QString unconfirmedBalance, QString immatureBalance, bool showImmature)
{
    labelBalance->setText(balance);
    labelUnconfirmed->setText(unconfirmedBalance);
    labelImmature->setText(immatureBalance);
    labelImmature->setVisible(showImmature);
    labelImmatureText->setVisible(showImmature);
}
