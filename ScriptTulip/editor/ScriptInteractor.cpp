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

#include "ScriptInteractor.h"

using namespace tlp;

ScriptInteractor::ScriptInteractor(const QString& name)
{
  this->_action = new InteractorAction(this, QIcon(), name);
}

void ScriptInteractor::draw(tlp::GlMainWidget* )
{

}

void ScriptInteractor::compute(tlp::GlMainWidget* )
{

}

tlp::InteractorAction* ScriptInteractor::getAction()
{
  return this->_action;
}

bool ScriptInteractor::isCompatible(const std::string& viewName)
{

}

void ScriptInteractor::remove()
{

}

void ScriptInteractor::install(QWidget* )
{

}

void ScriptInteractor::setView(tlp::View* view)
{

}

