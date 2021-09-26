// Copyright 2021 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <optional>
#include <string>

#include <QDialog>

#include "Common/CommonTypes.h"
#include "DiscIO/RiivolutionParser.h"

class QPushButton;
class QVBoxLayout;

class RiivolutionBootWidget : public QDialog
{
  Q_OBJECT
public:
  explicit RiivolutionBootWidget(std::string game_id, std::optional<u16> revision,
                                 std::optional<u8> disc, QWidget* parent = nullptr);
  ~RiivolutionBootWidget();

  bool ShouldBoot() const { return m_should_boot; }
  std::vector<DiscIO::Riivolution::Patch>& GetPatches() { return m_patches; }

private:
  void CreateWidgets();

  void LoadMatchingXMLs();
  void OpenXML();
  void MakeGUIForParsedFile(const std::string& path, DiscIO::Riivolution::Disc input_disc);
  void BootGame();

  std::string m_game_id;
  std::optional<u16> m_revision;
  std::optional<u8> m_disc_number;

  bool m_should_boot = false;
  std::vector<DiscIO::Riivolution::Disc> m_discs;
  std::vector<DiscIO::Riivolution::Patch> m_patches;

  QVBoxLayout* m_patch_section_layout;
};
