/*
 * HopTableModel.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _HOPTABLEMODEL_H
#define	_HOPTABLEMODEL_H

#include <QAbstractTableModel>
#include <QWidget>
#include <QModelIndex>
#include <QVariant>
#include <Qt>
#include <QItemDelegate>
#include <vector>
#include "hop.h"
#include "observable.h"

class HopTableModel;
class HopItemDelegate;

enum{HOPNAMECOL, HOPALPHACOL, HOPAMOUNTCOL, HOPUSECOL, HOPTIMECOL, HOPNUMCOLS /*This one MUST be last*/};

class HopTableModel : public QAbstractTableModel, public MultipleObserver
{
   Q_OBJECT
           
public:
   HopTableModel(QWidget* parent=0);
   void addHop(Hop* hop);
   bool removeHop(Hop* hop); // Returns true if "hop" is successfully found and removed.
   virtual void notify(Observable* notifier); // Inherited from Observer via MultipleObserver.
   
   // Inherit the following from QAbstractItemModel via QAbstractTableModel
   virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;
   virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;
   virtual QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const;
   virtual QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;
   virtual Qt::ItemFlags flags(const QModelIndex& index ) const;
   virtual bool setData( const QModelIndex& index, const QVariant& value, int role = Qt::EditRole );
   
private:
   std::vector<Hop*> hopObs;
};

class HopItemDelegate : public QItemDelegate
{
   Q_OBJECT
           
public:
   HopItemDelegate(QObject* parent = 0);
   
   // Inherited functions.
   virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
   virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
   virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
   
private:
};

#endif	/* _HOPTABLEMODEL_H */
