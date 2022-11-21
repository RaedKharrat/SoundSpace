#ifndef TAILBUTTONSDELEGATE_H
#define TAILBUTTONSDELEGATE_H

#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QStyledItemDelegate>
#include <QHeaderView>
#include <QPushButton>

class TailButtonsDelegate : public QStyledItemDelegate {
    Q_OBJECT
    Q_DISABLE_COPY(TailButtonsDelegate)
public:
    explicit TailButtonsDelegate(QObject* parent = Q_NULLPTR)
        :QStyledItemDelegate(parent)
    {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE{
        Q_ASSERT(index.isValid());
        QStyleOptionViewItem opt = option;
        initStyleOption(&opt, index);
        const QWidget *widget = option.widget;
        QStyle *style = widget ? widget->style() : QApplication::style();
        style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
        if(!(option.state & QStyle::State_Selected))
            return;
        QStyleOptionButton editButtonOption;
        editButtonOption.text = QString(QChar(0x270D)); //use emoji for text, optionally you can use icon + iconSize
        editButtonOption.rect = QRect(option.rect.left()+option.rect.width()-(2*option.rect.height()),option.rect.top(),option.rect.height(),option.rect.height());
        editButtonOption.features = QStyleOptionButton::None;
        editButtonOption.direction = option.direction;
        editButtonOption.fontMetrics = option.fontMetrics;
        editButtonOption.palette = option.palette;
        editButtonOption.styleObject = option.styleObject;

        QStyleOptionButton removeButtonOption(editButtonOption);
        removeButtonOption.text = QString(QChar(0x274C)); //use emoji for text, optionally you can use icon + iconSize
        removeButtonOption.rect = QRect(option.rect.left()+option.rect.width()-option.rect.height(),option.rect.top(),option.rect.height(),option.rect.height());
        style->drawControl(QStyle::CE_PushButton, &removeButtonOption, painter, widget);
    }
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE{
        const QSize baseSize = QStyledItemDelegate::sizeHint(option,index);
        return QSize(baseSize.width()+(2*baseSize.height()),baseSize.height());
    }
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE{
        QWidget* result = new QWidget(parent);
        result->setGeometry(option.rect);
        QWidget* baseEditor = QStyledItemDelegate::createEditor(result,option,index);
        baseEditor->setObjectName("baseEditor");
        baseEditor->setGeometry(0,0,option.rect.width()-(2*option.rect.height()),option.rect.height());
        QPushButton* editButton = new QPushButton(/*QChar(0x270D),*/ result);
        editButton->setObjectName("editButton");
        editButton->setGeometry(option.rect.width()-(2*option.rect.height()), 0, option.rect.height(),option.rect.height());
        connect(editButton,&QPushButton::clicked,[](){qDebug("Edit");});
        QPushButton* removeButton = new QPushButton(QChar(0x274C),result);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(option.rect.width()-option.rect.height(), 0, option.rect.height(),option.rect.height());
        connect(removeButton,&QPushButton::clicked,[](){qDebug("Remove");});
        return result;
    }
    void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE{
        QWidget* baseEditor = editor->findChild<QWidget*>("baseEditor");
        Q_ASSERT(baseEditor);
        QStyledItemDelegate::setEditorData(baseEditor,index);
    }
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const Q_DECL_OVERRIDE{
        QWidget* baseEditor = editor->findChild<QWidget*>("baseEditor");
        Q_ASSERT(baseEditor);
        QStyledItemDelegate::setModelData(baseEditor,model,index);
    }
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE{
        Q_UNUSED(index)
        editor->setGeometry(option.rect);
        QWidget* baseEditor = editor->findChild<QWidget*>("baseEditor");
        Q_ASSERT(baseEditor);
        baseEditor->setGeometry(0,0,option.rect.width()-(2*option.rect.height()),option.rect.height());
        QWidget* editButton = editor->findChild<QWidget*>("editButton");
        Q_ASSERT(editButton);
        editButton->setGeometry(option.rect.width()-(2*option.rect.height()), 0, option.rect.height(),option.rect.height());
        QWidget* removeButton = editor->findChild<QWidget*>("removeButton");
        Q_ASSERT(removeButton);
        removeButton->setGeometry(option.rect.width()-option.rect.height(), 0, option.rect.height(),option.rect.height());
        editor->setGeometry(option.rect);
    }
};

#endif // TAILBUTTONSDELEGATE_H

