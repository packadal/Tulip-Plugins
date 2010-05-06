/*
   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef SCRIPTINTERACTOR_H
#define SCRIPTINTERACTOR_H

#include <tulip/Interactor.h>


class ScriptInteractor : public tlp::Interactor
{

public:
  ScriptInteractor(const QString&);
  virtual void draw(tlp::GlMainWidget* );
  virtual void compute(tlp::GlMainWidget* );
  virtual tlp::InteractorAction* getAction();
  virtual bool isCompatible(const std::string& viewName);
  virtual void remove();
  virtual void install(QWidget* );
  virtual void setView(tlp::View* view);

private:
    tlp::InteractorAction* _action;
};

#endif // SCRIPTINTERACTOR_H
